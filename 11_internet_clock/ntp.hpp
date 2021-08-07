#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


struct timestamp
{
    unsigned int seconds;
    unsigned int fraction;

    time_t to_time_t()
    {
        return (this->seconds - ((70 * 365 + 17) * 86400)) & 0x7fffffff;
    }

    int reverse_endian_int(int n)
    {
        return
            (n & 0xff000000) >> 24 |
            (n & 0x00ff0000) >> 8  |
            (n & 0x0000ff00) << 8  |
            (n & 0x000000ff) << 24;
    }

    void reverse_endian()
    {
        this->seconds  = this->reverse_endian_int(this->seconds);
        this->fraction = this->reverse_endian_int(this->fraction);
    }
};

struct ntp_message
{
    unsigned int mode: 3;
    unsigned int version: 2;
    unsigned int leap: 2;

    // ---
    unsigned char stratum;
    unsigned char poll;
    unsigned char precision;
    unsigned int sync_distance;
    unsigned int drift_rate;
    unsigned char reference_id[4];

    // timestamps
    timestamp reference_timestamp;
    timestamp origin;
    timestamp receipt_time;
    timestamp transmit_time;
};



ntp_message recv_ntp(int sock)
{
    ntp_message buf;
    recv(sock, (char*)&buf, sizeof(ntp_message), 0);

    // ---
    buf.reference_timestamp.reverse_endian();
    buf.receipt_time.reverse_endian();
    buf.transmit_time.reverse_endian();
    buf.origin.reverse_endian();

    return buf;
}