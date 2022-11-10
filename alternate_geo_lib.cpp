class pt {
public:
    int x,y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(int d) {return {x*d, y*d};}
    pt operator/(int d) {return {x/d, y/d};}
};

long long cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}

long long  orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

bool above(pt a, pt p) {
    return p.y >= a.y;
}

bool crossesRay(pt a, pt p, pt q) {
    return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}

long long dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
bool inDisk(pt a, pt b, pt p) {
    return dot(a-p, b-p) <= 0;
}
bool onSegment(pt a, pt b, pt p) {
    return orient(a,b,p) == 0 && inDisk(a,b,p);
}
