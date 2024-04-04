#include "LinkedList.h"

using namespace std;

void Park::addBus(Bus bus) {
    setlocale(LC_ALL, "rus");
    inPark->add(bus.number, bus);
}

void Park::goOnRoute(Bus bus) {
    setlocale(LC_ALL, "rus");
    inPark->remove(bus.number);
    onRoute->add(bus.number, bus);
}

void Park::goInPark(Bus bus) {
    setlocale(LC_ALL, "rus");
    onRoute->remove(bus.number);
    inPark->add(bus.number, bus);
}

void Park::print() {
    setlocale(LC_ALL, "rus");
    cout << "Автобусы в парке: " << endl;
    auto pvp = inPark->pBeg;
    while (pvp != nullptr) {
        cout << "Номер: " << pvp->data.number << ", маршрут: " << pvp->data.route << ", водитель: " << pvp->data.driver
             << endl;
        pvp = pvp->next;
    }

    cout << "Автобусы на маршруте: " << endl;
    auto pvr = onRoute->pBeg;
    while (pvr != nullptr) {
        cout << "Номер: " << pvr->data.number << ", маршрут: " << pvr->data.route << ", водитель: " << pvr->data.driver
             << endl;
        pvr = pvr->next;
    }
}