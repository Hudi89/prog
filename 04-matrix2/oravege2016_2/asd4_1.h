#ifndef ASD4_1_H_INCLUDED
#define ASD4_1_H_INCLUDED

enum Exception{
    EMPTY_VECTOR,
    WRONG_INPUT_FORMAT,
    NEGATIVE_COUNT,
    NEED_KNIGHT
};

template<class T>
int findMax(const std::vector<T> &v){
    if(v.size() == 0){
        throw EMPTY_VECTOR;
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

float feladat(const std::vector<std::vector<float> > &m){
    if(m.size() == 0){
        throw NEED_KNIGHT;
    }
    float s = 0;
    for(int i=0;i<m.size();i++){
        float temp = m[i][findMax(m[i])];
        std::cout <<temp << std::endl;
        s = s + temp;
    }
    return s / m.size();
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
    v2.resize(n);
    for(int a=0;a<n;a++){
        in >> v2[a];
        if(in.fail()){
            throw WRONG_INPUT_FORMAT;
        }
    }
    return in;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &v2){
    out << v2.size() << std::endl;
    for(int a=0;a<v2.size();a++){
        out << v2[a] << std::endl;
    }
    return out;
}

#endif // ASD4_1_H_INCLUDED
