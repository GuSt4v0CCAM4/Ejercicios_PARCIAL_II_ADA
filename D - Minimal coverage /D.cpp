#include <iostream>
#include <vector>
#include <algorithm>

class Segment {
public:
    int L, R;

    Segment(int l, int r) : L(l), R(r) {}
};

bool comp(const Segment& s1, const Segment& s2) {
    return s1.L < s2.L;
}

class SegmentSolver {
private:
    std::vector<Segment> segments;
    int target;

public:
    SegmentSolver(int t) : target(t) {}

    void addSegment(int l, int r) {
        segments.emplace_back(l, r);
    }

    void solve() {
        std::sort(segments.begin(), segments.end(), comp);

        int curL = 0, rReach = 0;
        size_t i = 0;
        std::vector<Segment> selectedSegments;

        while (rReach < target && i < segments.size()) {
            int newL = curL;
            size_t farthest = i;

            for (; i < segments.size(); ++i) {
                if (segments[i].L > curL)
                    break;
                else if (segments[i].R >= newL) {
                    newL = segments[i].R;
                    farthest = i;
                }
            }

            if (farthest == i)
                break;

            selectedSegments.push_back(segments[farthest]);
            curL = rReach = newL;
        }

        if (rReach >= target) {
            std::cout << selectedSegments.size() << std::endl;
            for (const auto& segment : selectedSegments)
                std::cout << segment.L << " " << segment.R << std::endl;
        } else {
            std::cout << "0" << std::endl;
        }
    }
};

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int M;
        std::cin >> M;

        SegmentSolver solver(M);

        int l, r;
        while (std::cin >> l >> r, !(l == 0 && r == 0))
            solver.addSegment(l, r);

        solver.solve();

        if (T)
            std::cout << std::endl;
    }

    return 0;
}

