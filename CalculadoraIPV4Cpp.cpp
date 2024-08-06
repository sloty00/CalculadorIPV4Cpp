// CalculadoraIPV4Cpp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Función para convertir una dirección IP a un número entero
uint32_t ipToInt(const string& ip) {
    uint32_t result = 0;
    istringstream iss(ip);
    string byte;
    while (getline(iss, byte, '.')) {
        result = (result << 8) | stoi(byte);
    }
    return result;
}

// Función para convertir un número entero a una dirección IP
string intToIp(uint32_t ip) {
    ostringstream oss;
    oss << ((ip >> 24) & 0xFF) << '.'
        << ((ip >> 16) & 0xFF) << '.'
        << ((ip >> 8) & 0xFF) << '.'
        << (ip & 0xFF);
    return oss.str();
}

// Función para calcular y mostrar las subredes
void printSubnets(const string& baseIP, int prefix) {
    // Máscara de subred original
    uint32_t mask = ~((1 << (32 - prefix)) - 1);
    uint32_t baseIpInt = ipToInt(baseIP);

    // Tamaño de la subred
    uint32_t subnetSize = 1 << (32 - prefix);
    uint32_t numSubnets = 1 << (prefix - 24); // Número de subredes posibles

    cout << left << setw(20) << "Dirección Subred"
        << setw(20) << "Broadcast"
        << setw(20) << "Primer Equipo"
        << setw(20) << "Último Equipo"
        << setw(20) << "Máscara" << endl;

    for (int i = 0; i < numSubnets; ++i) {
        uint32_t subnetBase = baseIpInt + (i * subnetSize);
        uint32_t broadcastBase = subnetBase + subnetSize - 1;
        string subnetIP = intToIp(subnetBase);
        string broadcastIP = intToIp(broadcastBase);
        string firstHostIP = intToIp(subnetBase + 1);
        string lastHostIP = intToIp(broadcastBase - 1);
        string maskIP = intToIp(mask);

        cout << left << setw(20) << subnetIP
            << setw(20) << broadcastIP
            << setw(20) << firstHostIP
            << setw(20) << lastHostIP
            << setw(20) << maskIP << endl;
    }
}

int main() {
    string baseIP;
    int prefix;

    cout << "Ingrese la dirección IP base (ejemplo: 192.168.1.0): ";
    cin >> baseIP;
    cout << "Ingrese el prefijo CIDR (ejemplo: 25): ";
    cin >> prefix;

    printSubnets(baseIP, prefix);

    return 0;
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
