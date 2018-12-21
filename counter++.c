#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

volatile int freakout = 0;

void sig() {
    freakout = 1;
}

int main(void) {

    signal(SIGINT, &sig);

    uint64_t cnt = 0;

    while (1) {

        getchar();
        cnt++;
        printf("counter++: %" PRIu64 "\n", cnt);

        while (freakout) {
            printf("\a");
        }

    }

}
