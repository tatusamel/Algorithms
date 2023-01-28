
const int maxn = 1e5+5;

int arr[maxn], seg[4*maxn];
int n;

void upd(int ind, int l, int r, int tg, int new_value) {
    
    // tamamen disinda ise araligin biseyi guncellemeden geri don
    // tg o sayinin arraydeki yeri aslinda
    if ( l > tg || r < tg ) {
        return;
    }
    
    if ( l == r ) { //e ger sagliyorsa
        seg[ind] = new_value;
        return;
    }
    
    // eger base caseleri saglamiyorsa cocuklarina hallettir
    
    upd( ind*2, l, (l+r)/2, tg, new_value ); // sol cocuk
    upd( ind*2+1, (l+r)/2+1, r, tg, new_value ); // sag cocuk
    
    seg[ind] = seg[ind*2] + seg[ind*2+1]; // asagidan yukari giderken, ayni anda guncelle
}

int find(int ind, int l, int r, int tg_l, int tg_r ) {
    
    // iki durum var araligin disinda ise ve araligin tamamen icinde ise
    
    // tamamen disinda olma durumu
    if ( l > tg_r || r < tg_l ) {
        return 0;
    }
    // tamamen icinde
    if ( tg_l <= l && r <= tg_r ) {
        return seg[ind];
    }
    
    // eger su anki nodedan bir sey karar veremiyorsak
    // sorumluluklari cocuklara paylastir
    
    int ans_left = find(2*ind, l, (l+r)/2, tg_l, tg_r );
    int ans_right = find(2*ind+1, (l+r)/2+1, r, tg_l, tg_r);
    
    return ans_left + ans_right;
}

// build asamasi
void init( int ind, int l, int r ) {
    
    if ( l == r ) { // leafe ulastik
        seg[ind] = arr[l];
        return;
    }
    
    init ( 2*ind, l , (l+r)/2 );
    init ( 2*ind+1, (l+r)/2 + 1, r);
    
    seg[ind] = seg[ind*2] + seg[ind*2+1]; // toplami bulmak icin
}
void segmentTree() {
    
    cin >> n;
    
    for( int i = 1; i <=n; i++ ) cin >> arr[i];
    
    init(1, 1, n); // root = 1, 1 ve n arasi
    
    //queryleri alalim
    int Q; cin >> Q;
    
    int ty,a,b;
    // if ty == 1 -> aralik sorgulama
    while ( Q-- ) {
        
        cin >> ty >> a >> b;
        if ( ty == 1 ) { //aralik sorgualma
            // a ve b arasini sorgula toplam degerini
            int ans = find(1,1,n,a,b);
        }
        else { // update
            // a indexindeki degeri b yap diyoruz
            // 1 nodeundan basla, su anki aralik 1 n arasi. ve a b hep ayni kalcak
            upd(1,1,n,a,b);
        }
    }
    
}
