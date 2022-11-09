
// OB vector
pair<long long, long long> make_vec(pair<long long, long long> y, pair<long long, long long> x) {
    return make_pair(x.first - y.first, x.second - y.second);
}

// absolute value of a vector
double vec_abs(pair<long long, long long> x) {
    return sqrt(x.first * x.first + x.second * x.second);
}

// vector cross product, note that aXb != bXa
long long vec_crossP(pair<long long, long long> x, pair<long long, long long> y) {
    return x.first * y.second - x.second * y.first;
}

// vector dot product
long long vec_dotP(pair<long long, long long> x, pair<long long, long long> y) {
    return x.first * y.first + x.second * y.second;
}

// angle between two vector [0,pi]
double vec_angle(pair<long long, long long> x, pair<long long, long long> y) {
    return acos(clamp(vec_dotP(x, y) / vec_abs(x) / vec_abs(y), -1.0, 1.0));
}

// distance between two pts
double pt_dist(pair<long long, long long> x, pair<long long, long long> y) {
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

//segment to point distance
double seg_to_pt_dist(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> p) {
    if (vec_angle(make_vec(a, b), make_vec(a, p)) > pi / 2)
        return pt_dist(a, p);
    else if (vec_angle(make_vec(b, a), make_vec(b, p)) > pi / 2)
        return pt_dist(b, p);
    return abs(vec_crossP(make_vec(a, b), make_vec(a, p))) / vec_abs(make_vec(a, b));
}

//proper intersection of two segments
bool seg_intersect(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c,
                   pair<long long, long long> d) {
    bool cd_in_two_side = (vec_crossP(make_vec(a, b), make_vec(a, c)) * vec_crossP(make_vec(a, b), make_vec(a, d))) < 0;
    bool ab_in_two_side = (vec_crossP(make_vec(c, d), make_vec(c, a)) * vec_crossP(make_vec(c, d), make_vec(c, b))) < 0;
    return cd_in_two_side & ab_in_two_side;
}

// intersection point of two line
pair<double, double> intersect_pt_of_line(vector<long long> &a, vector<long long> &b) {
    double d = a[0] * b[1] - b[0] * a[1];
    if (d == 0) return {-1, -1};
    return {(a[1] * b[2] - b[1] * a[2]) / d, (b[0] * a[2] - a[0] * b[2]) / d};
}

// 2 point to ax+by+c=0 line
vector<long long> pt_to_line(pair<long long, long long> a, pair<long long, long long> b) {
    long long d = a.second - b.second, c = a.first - b.first;
    return {d, -c, -a.first * d + a.second * c};
}

//if normal vector of a line is (a,b) the line is ax+by+c=0
