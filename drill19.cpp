#include <iostream>
#include <vector>

using namespace std;

template <typename T> struct S {
    private:
    T val;

    public:
    S(T val) {
        this->val = val;
    }

    T& get();
    const T& getConst();

    void operator=(const T& val) {
        this->val = val;
    }
};

template <typename T> T& S<T>::get() {
    return val;
}

template <typename T> const T& S<T>::getConst() {
    return val;
}

template <typename T> void read_val(T& v) {
    cin >> v;
}

int main() {
    S<int> intHolder(2);
    S<char> charHolder('x');
    S<double> doubleHolder(7.2);
    S<string> stringHolder("The sky is blue");
    S<vector<int> > vectorHolder(vector<int>());

    read_val(intHolder.get());
    cout << intHolder.get() << endl;

    read_val(charHolder.get());
    cout << charHolder.get() << endl;

    read_val(doubleHolder.get());
    cout << doubleHolder.get() << endl;

    read_val(stringHolder.get());
    cout << stringHolder.get() << endl;
    return 0;
}