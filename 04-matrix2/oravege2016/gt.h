#ifndef GT_H_INCLUDED
#define GT_H_INCLUDED


template<class T>
int findMax(const std::vector<T> &v){
    if(v.size() == 0){
        throw VECTOR_IS_EMPTY;
    }
    T max = v[0];
    int ind = 0;
    for(int i=1;i<=v.size()-1;i++){
        if(max < v[i]){
            max = v[i];
            ind = i;
        }
    }
    return ind;
}

bool ls(const std::vector<std::vector<std::string> > &m, int &ind){
    bool l = false;
    int i = 0;
    while(!l && i < m.size()){
        l = m[i][findMax(m[i])].find('c') != std::string::npos;
        ind = i;
        i= i + 1;
    }
    return l;
}

#endif // GT_H_INCLUDED
