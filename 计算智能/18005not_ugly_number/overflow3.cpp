include <cstdio>
#include <set>

using namespace std;

const unsigned N = 10000000;

set<unsigned> uglys;
unsigned n_collis = 0;


void srch_ugly(unsigned n)
{
    if (uglys.find(n) != uglys.end()) { /* found in set */
        ++n_collis;
    } else {
        uglys.insert(n);
        if (2*n < N) srch_ugly(2*n);
        if (3*n < N) srch_ugly(3*n);
        if (5*n < N) srch_ugly(5*n);
    } /* if */
} /* srch_ugly(unsigned) */

int main()
{
    unsigned col = 0; /* printing column */

    srch_ugly(1);

    /* print results */    
    printf("%lu uglys.  %u collissions.\n", uglys.size(), n_collis);
    for (set<unsigned>::iterator i = uglys.begin();
            i != uglys.end();
            ++i)
    {
        if (col >= 72) {
            puts("");
            col = 0;
        } /* if */
        col += printf("%s%i", col ? " " : "", *i);
    } /* for */
    if (col) puts("");
} /* main */