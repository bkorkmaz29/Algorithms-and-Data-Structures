#ifndef PRODUCE_H_INCLUDED
#define PRODUCE_H_INCLUDED

#include <iostream>
#include "Sequence.h"


template <typename Key, typename Info>
Sequence<Key, Info> Produce (const Sequence<Key, Info> & seq_1, int start_1, int len_1,
        const Sequence<Key, Info> & seq_2, int start_2, int len_2, int limit){

    Sequence<Key, Info> s1 = seq_1;
    Sequence<Key, Info> s2 = seq_2;
    Sequence<Key, Info> produced;

    bool s1Done = false;
    bool s2Done = false;
    int chunks = 0; // no of produced chunks
    int shift_1 = 0; //shift of the current element for 1. sequence
    int shift_2 = 0; //shift of the current element for 2. sequence


    if((start_1 + len_1)  > s1.Count() )
        throw  std::invalid_argument( "Invalid starting point or length for 1. Sequence" );
    if((start_2 + len_2)  > s2.Count() )
        throw  std::invalid_argument("Invalid starting point or length for 2. Sequence");
    if( start_1 < 0 || start_2 < 0 || len_1 <= 0 || len_2 <= 0 || limit <= 0 )
        throw  std::invalid_argument( "Invalid parameters" );


    while((!s1Done || !s2Done))   {
        //checks if next chunk will exceed limit
        if (chunks + 1 > limit ){
            s1Done = true;
            s2Done = true;
            }
        //checks if Sequences are large enough
        if(( s1.IsNull(shift_1 + start_1 + len_1 - 1) || s2.IsNull(shift_2 + start_2 + len_2 - 1))){
            s1Done = true;
            s2Done = true;
            }
            //producing chunk
            for (int i = 0; !s1Done && i < len_1; ++i) {
                    produced.PushBack(s1.GetKeyAt(i + shift_1 + start_1), s1.GetInfoAt(i + shift_1 + start_1));
                }

            for (int i = 0; !s2Done && i < len_2; ++i) {
                        produced.PushBack(s2.GetKeyAt(i + shift_2 + start_2), s2.GetInfoAt(i + shift_2 + start_2));
            }

        chunks++;
        shift_1 = shift_1 + len_1;
        shift_2 = shift_2 + len_2;
    }

    return produced;
}

#endif // PRODUCE_H_INCLUDED

