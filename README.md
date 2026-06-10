# Calculadora de Redes IPv4 en C++

Este proyecto es una calculadora de redes IPv4 escrita en C++ que permite calcular las subredes, direcciones de red, direcciones de broadcast, y direcciones utilizable de una red dada. También genera una tabla con la información de todas las subredes.

## Funcionalidades

- **Cálculo de Subredes:** Dada una dirección IP base y un prefijo CIDR, calcula la dirección de red, la dirección de broadcast, la máscara de subred, la primera y última dirección utilizable.
- **Tabla de Subredes:** Muestra una tabla con todas las subredes derivadas de la red principal y sus respectivas direcciones de red, broadcast, primer y último equipo utilizable, y máscara de subred.

## Requisitos

- **Compilador:** Compatible con C++ (Visual Studio Profesional).
- **Sistema Operativo:** Windows o cualquier sistema que soporte el compilador C++ utilizado.

## Uso

1. **Compilar el Proyecto:**
   Abre el proyecto en Visual Studio Profesional y compílalo. Asegúrate de tener configurado el entorno correctamente.

2. **Ejecutar la Aplicación:**
   Ejecuta el archivo binario generado. La aplicación te pedirá que ingreses una dirección IP base y un prefijo CIDR. Luego mostrará la información calculada.

## Ejemplo

```plaintext
Ingrese la dirección IP base (ejemplo: 192.168.1.0): 192.168.1.0
Ingrese el prefijo CIDR (ejemplo: 25): 25

Dirección Subred      Broadcast        Primer Equipo   Último Equipo    Máscara
192.168.1.0           192.168.1.127    192.168.1.1    192.168.1.126    255.255.255.128
192.168.1.128         192.168.1.255    192.168.1.129  192.168.1.254    255.255.255.128
