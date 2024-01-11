#include <iostream>
#include<vector>

using namespace std;


void Printvtr( vector<int> const& v ) {
    for( auto const& var : v ) {
        cout << var  << "\t";
    }
    cout << endl;
}

void BruteForce( vector<int> const& v1, vector<int> const& v2, int n, int m ) {
    vector<int> v3( n + m );
    int i = 0;
    int j = 0;
    int index = 0;
    while( i < n && j < m ) {
        if( v1[ i ] <= v2[ j ] ) {
            v3[ index ] = v1[ i ];
            i++;
            index++;
        }
        else {
            v3[ index ] = v2[ j ];
            j++;
            index++;
        }
    }
    
    while( i < n ) {
        v3[ index++ ] = v1[ i++ ];
    }
    
    while( j < m ) {
        v3[ index++ ] = v2[ j++ ];
    }
    
    Printvtr( v3 );
}

void SwapIfGreater( vector<int>& v1, vector<int>& v2, int n, int m ) {
    if( v1[ n ] > v2[ m ] ) {
        int temp = v1[ n ];
        v1[ n ] = v2[ m ];
        v2[ m ] = temp;
    }
}

void Optimal( vector<int>& v1, vector<int>& v2, int n, int m ) {
    int length = n + m;
    int gap = length / 2 + length % 2;
    
    while( gap > 0 ) {
        int left = 0;
        int right = left + gap;   
        while( right < length ) {
            if( left < n && right >= n ) {
                SwapIfGreater( v1, v2, left, right - n );
            }
            else if( left >= n && right >= n ) {
                SwapIfGreater( v1, v2, left - n , right - n );
            }
            else {
                SwapIfGreater( v1, v2, left, right );
            }
            
            left++;
            right++;
        }
        
        if( gap == 1 ) break;
        gap = gap/2 + gap % 2;
    }
}


void MergeSortedArray( vector<int>& v1, vector<int>& v2, int n, int m ) {
    BruteForce( v1, v2, n, m );
    Optimal( v1, v2, n, m );
    Printvtr( v1 );
    Printvtr( v2 );
}

int main()
{
    vector<int> v1 = { 1, 5 , 7, 10 };
    vector<int> v2 = { 2, 4, 6, 12, 14 };
    
    MergeSortedArray( v1, v2, v1.size(), v2.size() );

    return 0;
}
