#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

class Coordenada {
public:
    double x;
    double y;

    Coordenada(double _x, double _y) : x(_x), y(_y) {}
};

bool cmp(const Coordenada& a, const Coordenada& b) {
    return a.x < b.x;
}

class ClosestPair {
private:
    double Distance(const Coordenada& a, const Coordenada& b) {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    }

    double Divide(const std::vector<Coordenada>& puntos, int low, int high) {
        if (low >= high)
            return 99999;

        int mid = (low + high) / 2;
        double min_left = Divide(puntos, low, mid);
        double min_right = Divide(puntos, mid + 1, high);

        return Combine(puntos, low, mid, high, min_left, min_right);
    }

    double Combine(const std::vector<Coordenada>& puntos, int low, int mid, int high, double min_left, double min_right) {
        double d = (min_left < min_right) ? min_left : min_right;
        double line = (puntos[mid].x + puntos[mid + 1].x) * 0.5;
        double min_D = d;

        for (int i = mid + 1; puntos[i].x < line + d && i <= high; i++) {
            for (int j = mid; puntos[j].x > line - d && j >= low; j--) {
                double temp = Distance(puntos[i], puntos[j]);
                if (temp < min_D)
                    min_D = temp;
            }
        }

        return min_D;
    }

public:
    void FindClosestPair(int N) {
        std::vector<Coordenada> puntos;

        for (int i = 0; i < N; i++) {
            double x, y;
            std::cin >> x >> y;
            puntos.emplace_back(x, y);
        }

        std::sort(puntos.begin(), puntos.end(), cmp);

        double dis = Divide(puntos, 0, N - 1);
        if (dis >= 10000.0) {
            std::cout << "INFINITY" << std::endl;
        } else {
            printf("%.4lf\n", dis);
        }
    }
};

int main() {
    int N;
    ClosestPair closestPair;

    while (std::cin >> N) {
        if (N == 0)
            break;
        closestPair.FindClosestPair(N);
    }

    return 0;
}
