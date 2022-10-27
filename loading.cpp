// OB vector
pair<long long, long long> make_vec(pair<long long, long long> y, pair<long long, long long> x) {
    return make_pair(x.first - y.first, x.second - y.second);
}

// absolute value of a vector
double vec_abs(pair<long long, long long> x) {
    return sqrt(x.first * x.first + x.second * x.second);
}

// vector cross product, note that aXb != bXa
long long vec_cross(pair<long long, long long> x, pair<long long, long long> y) {
    return x.first * y.second - x.second * y.first;
}

// vector dot product
long long vec_dot(pair<long long, long long> x, pair<long long, long long> y) {
    return x.first * y.first + x.second * y.second;
}

// angle between two vector [0,pi]
double vec_angle(pair<long long, long long> x, pair<long long, long long> y) {
    return acos(clamp(vec_dot(x, y) / vec_abs(x) / vec_abs(y), -1.0, 1.0));
}

// distance between two points
double point_dis(pair<long long, long long> x, pair<long long, long long> y) {
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}
