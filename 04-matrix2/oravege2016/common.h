#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED


enum Exception{
    VECTOR_IS_EMPTY,
    WRONG_INPUT_FORMAT,
    NEGATIVE_COUNT,
    TEAPOT=418
};


template<class T>
void matrixBeolvas(std::istream &in, std::vector<std::vector<T> > &m ){
    int w,h;
    in >> w>> h;
    m.resize(h);
    for(int a =0;a<h;a++){
        m[a].resize(w);
        for(int b = 0;b<w;b++){
            in >> m[a][b];
        }
    }
}

template<class T>
void matrixKiir(std::ostream &out, std::vector<std::vector<T> > &m ){
    if(m.size() == 0){
        out << "0 ";
    }else{
        out << m[0].size() << " ";
    }

    out << m.size() << std::endl;
    for(int a =0;a<m.size();a++){
        for(int b = 0;b<m[0].size();b++){
            out << m[a][b] << " ";
        }
        out << std::endl;
    }
}
template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &v2){
    int n;
    in >> n;
    if(in.fail()){
        throw WRONG_INPUT_FORMAT;
    }
    if(n < 0){
        throw NEGATIVE_COUNT;
    }
    for(int a=0;a<n;a++){
        T temp;
        in >> temp;
        if(in.fail()){
            throw WRONG_INPUT_FORMAT;
        }
        v2.push_back(temp);
    }
    return in;
}
template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &v2){
    out <<v2.size() << std::endl;
    for(int a=0;a<v2.size();a++){
        out << v2[a] << std::endl;
    }
    return out;
}

#endif // COMMON_H_INCLUDED
