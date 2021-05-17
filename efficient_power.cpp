// O(logn) - power operation
llt power(llt b, llt e) {
    if(e==0) 
        return 1;
    
    if(e%2==0) {
        llt temp = power(b,e/2)%MOD;
        return temp*temp%MOD;
    }
    else {
        llt temp = power(b,(e-1)/2)%MOD;
        return b*temp*temp%MOD;
    }
}