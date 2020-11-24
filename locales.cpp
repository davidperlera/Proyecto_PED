#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct producto{
    string name;
    float precio_unitario;
};

struct cliente{
    string nombre;
    vector<producto> compras;
}; 
producto obtener_productos_local1(int opcion);
producto obtener_producto_local2(int opcion); 
producto obtener_producto_local3(int opcion); 
void Agregar_clientes(queue<cliente>&local1);
void Agregar_clientes2(queue<cliente>&local2);
void Agregar_clientes3(queue<cliente>&Local3);
float monto(queue<cliente>&local);
int menu_local1();
int menu_local2();
int menu_local3();
void mostrar_clientes(queue<cliente>&Local);
void Mayor_venta(queue<cliente>&Local1,queue<cliente>&Local2,queue<cliente>&Local3);

int main(){

    bool continuar=true;

queue<cliente> Local1;
queue<cliente> Local2;
queue<cliente> Local3;
do{
    int opcion; 

    cout<<" 1) Agregar cliente a la cola del local Samsung "<<endl;
    cout<<" 2) Agregar cliente a la cola del local Apple"<<endl;
    cout<<" 3) Agregar cliente a la cola del local Huawei "<<endl;
    cout<<" 4) Mostrar cola de clientes del local Samsung"<<endl;
    cout<<" 5) Mostrar cola de clientes del local Apple" <<endl;
    cout<<" 6) Mostrar cola de clientes del local Huawei"<<endl;
    cout<<" 7) Ver las ganancias del local1"<<endl;
    cout<<" 8) Ver las ganancias del local2"<<endl;
    cout<<" 9) Ver las ganancias del local3"<<endl;
    cout<<" 10) Mostrar quien tuvo mas ventas"<<endl;
    cout<<" 11) Salir del programa"<<endl;
    cout<<"  Ingresa una opcion:";
    cin>>opcion; cin.ignore();
     
     switch(opcion){

         case 1: Agregar_clientes(Local1); break;
         case 2: Agregar_clientes2(Local2); break;
         case 3: Agregar_clientes3(Local3); break;
         case 4: if(!Local1.empty()){mostrar_clientes(Local1);}else{cout<<endl<<endl<<"La cola esta vacia"<<endl<<endl;} break;
         case 5: if(!Local2.empty()){mostrar_clientes(Local2);}else{cout<<endl<<endl<<"La cola esta vacia"<<endl<<endl;} break;
         case 6: if(!Local3.empty()){mostrar_clientes(Local3);}else{cout<<endl<<endl<<"La cola esta vacia"<<endl<<endl;} break;
         case 7: if(!Local1.empty()){cout<<"El monto de venta es: "<<monto(Local1)<<endl<<endl;}
         else{cout<<endl<<endl<<"No hubo ventas en el local la cola esta vacia"<<endl<<endl;}  break;
         case 8: if(!Local2.empty()){cout<<"El monto de venta es: "<<monto(Local2)<<endl<<endl;}
         else{cout<<endl<<endl<<"No hubo ventas en el local la cola esta vacia"<<endl<<endl;}  break;
         case 9:if(!Local3.empty()){cout<<"El monto de venta es: "<<monto(Local3)<<endl<<endl;}
         else{cout<<endl<<endl<<"No hubo ventas en el local la cola esta vacia"<<endl<<endl;}  break;
         case 10: Mayor_venta(Local1,Local2,Local3); break;
         case 11: cout<<endl<<endl<<"Fin del programa"<<endl<<endl;continuar=false; break;
         default: cout<<"Opci"<<char(162)<<"n no v"<<char(160)<<"lida"<<endl;
     }
}while(continuar);

    
    return 0;}

producto obtener_producto_local1(int opcion){
    producto nuevoProducto;
    switch(opcion){
        case 1: nuevoProducto.name = "Galaxy S20 ";
                nuevoProducto.precio_unitario = 800;
                break;

        case 2: nuevoProducto.name = "Galaxy Note 20 Ultra"; 
                nuevoProducto.precio_unitario = 1299;
                break;
                
        case 3: nuevoProducto.name = "Galaxy Z Fold 2";
                nuevoProducto.precio_unitario = 1999;
                break;
                
        case 4: nuevoProducto.name = "Galaxy Tab S7";
                nuevoProducto.precio_unitario = 650;
                break;
                
        case 5: nuevoProducto.name = "Galaxy Watch 3";
                nuevoProducto.precio_unitario = 400;
                break;
        
        case 6: nuevoProducto.name = "Galaxy A71";
                nuevoProducto.precio_unitario = 550;
                break;
                
        case 7: nuevoProducto.name = "Galaxy Buds live";
                nuevoProducto.precio_unitario = 169;
                break;
                
        case 8: nuevoProducto.name = "Galxy S20 Ultra";
                nuevoProducto.precio_unitario = 1399;
                break;
                
        case 9: nuevoProducto.name = "Odyssey G5";
                nuevoProducto.precio_unitario = 364;
                break;
    }
    return nuevoProducto;
}

void Agregar_clientes(queue<cliente>&local1){
    cliente nuevoCliente;
    int opcion;
    bool continuar=true;

    cout<<"Ingrese su nombre y apellido: ";
    getline(cin,nuevoCliente.nombre);

    do{
    opcion=menu_local1();

        switch(opcion){

            case 1: nuevoCliente.compras.push_back(obtener_producto_local1(1)); break;
            case 2: nuevoCliente.compras.push_back(obtener_producto_local1(2)); break;
            case 3: nuevoCliente.compras.push_back(obtener_producto_local1(3)); break;
            case 4: nuevoCliente.compras.push_back(obtener_producto_local1(4)); break;
            case 5: nuevoCliente.compras.push_back(obtener_producto_local1(5)); break;
            case 6: nuevoCliente.compras.push_back(obtener_producto_local1(6)); break;
            case 7: nuevoCliente.compras.push_back(obtener_producto_local1(7)); break;
            case 8: nuevoCliente.compras.push_back(obtener_producto_local1(8)); break;
            case 9: nuevoCliente.compras.push_back(obtener_producto_local1(9)); break;
            case 10: continuar=false; break;
            default: cout<<"opcion no valida."<<endl;
        }
    }while(continuar);
    local1.push(nuevoCliente);
}

int menu_local1(){
    int opcion;
    cout<<"Productos disponibles."<<endl<<endl;
     
    cout<<"1) \t\t 2) \t\t\t 3)"<<endl;
    cout<<"Galaxy S20 \t Galaxy Note 20 Ultra \t Galaxy Z Fold 2"<<endl;
    cout<<"Precio: $800 \t Precio: $1299 \t\t Precio: $1999"<<endl<<endl;

    cout<<"4) \t\t 5) \t\t\t 6)"<<endl;
    cout<<"Galaxy Tab S7 \t Galaxy Watch 3 \t Galaxy A71"<<endl;
    cout<<"Precio: $650 \t Precio: $400 \t\t Precio: $550"<<endl<<endl;

    cout<<"7) \t\t 8) \t\t\t 9)"<<endl;
    cout<<"Galaxy Buds live Galxy S20 Ultra \t Odyssey G5"<<endl;
    cout<<"Precio: $169 \t Precio: $1399 \t\t Precio: $364"<<endl<<endl; 
    cout<<"10) Regresar"<<endl;

    cout<<"Ingresa la opcion que deseas:";
    cin>>opcion; cin.ignore();
    
  

    return opcion;

}

float monto(queue<cliente>&local){

    queue<cliente>copia=local;
    cliente Cliente;
    producto newproduct;
    float total=0;

    while(!copia.empty()){
        Cliente=copia.front();
        while(!Cliente.compras.empty()){
            newproduct=Cliente.compras.back();
            total+=newproduct.precio_unitario;
            Cliente.compras.pop_back();
        }
        copia.pop();
}
    return total;
}
int menu_local2(){
    int opcion;
    cout<<"Productos disponibles."<<endl<<endl;
     
    cout<<"1) \t\t 2) \t\t 3)"<<endl;
    cout<<"Iphone 12 \t Iphone 12 Pro \t Air pods"<<endl;
    cout<<"Precio: $1280 \t Precio: $1500 \t Precio: $159"<<endl<<endl;

    cout<<"4) \t\t 5) \t\t 6)"<<endl;
    cout<<"Ipad Pro 2020 \t Ipad Air 2020 \t Ipad mini"<<endl;
    cout<<"Precio: $999 \t Precio: $599 \t Precio: $399"<<endl<<endl;

    cout<<"7) \t\t 8) \t\t 9)"<<endl;
    cout<<"Watch series 6 \t Macbook air \t Macbook pro"<<endl;
    cout<<"Precio: $449 \t Precio: $849 \t Precio: $1299"<<endl<<endl;

    cout<<"10) Regresar"<<endl;

    cout<<"Ingresa la opcion que deseas:";
    cin>>opcion; cin.ignore();
    
   
    return opcion;
    
    

}

void Agregar_clientes2(queue<cliente>&local2){
    cliente nuevoCliente;
    int opcion;
    bool continuar=true;

    cout<<"Ingrese su nombre y apellido: ";
    getline(cin,nuevoCliente.nombre);

    do{
    opcion=menu_local2();

        switch(opcion){

            case 1: nuevoCliente.compras.push_back(obtener_producto_local2(1)); break;
            case 2: nuevoCliente.compras.push_back(obtener_producto_local2(2)); break;
            case 3: nuevoCliente.compras.push_back(obtener_producto_local2(3)); break;
            case 4: nuevoCliente.compras.push_back(obtener_producto_local2(4)); break;
            case 5: nuevoCliente.compras.push_back(obtener_producto_local2(5)); break;
            case 6: nuevoCliente.compras.push_back(obtener_producto_local2(6)); break;
            case 7: nuevoCliente.compras.push_back(obtener_producto_local2(7)); break;
            case 8: nuevoCliente.compras.push_back(obtener_producto_local2(8)); break;
            case 9: nuevoCliente.compras.push_back(obtener_producto_local2(9)); break;
            case 10: continuar=false; break;
            default: cout<<"opcion no valida."<<endl;
        }
    }while(continuar);
    local2.push(nuevoCliente);
}

producto obtener_producto_local2(int opcion){
    producto nuevoProducto;
    switch(opcion){
        case 1: nuevoProducto.name = "Iphone 12 ";
                nuevoProducto.precio_unitario = 1280;
                break;

        case 2: nuevoProducto.name = "Iphone 12 Pro"; 
                nuevoProducto.precio_unitario = 1500;
                break;
                
        case 3: nuevoProducto.name = "Air pods";
                nuevoProducto.precio_unitario = 159;
                break;
                
        case 4: nuevoProducto.name = "Ipad Pro 2020";
                nuevoProducto.precio_unitario = 999;
                break;
                
        case 5: nuevoProducto.name = "Ipad Air 2020";
                nuevoProducto.precio_unitario = 599;
                break;
        
        case 6: nuevoProducto.name = "Ipad mini";
                nuevoProducto.precio_unitario = 399;
                break;
                
        case 7: nuevoProducto.name = "Watch series 6";
                nuevoProducto.precio_unitario = 449;
                break;
                
        case 8: nuevoProducto.name = "Macbook air";
                nuevoProducto.precio_unitario = 849;
                break;
                
        case 9: nuevoProducto.name = "Macbook pro";
                nuevoProducto.precio_unitario = 1299;
                break;
    }
    return nuevoProducto;
}

int menu_local3(){
    int opcion;
    cout<<"Productos disponibles."<<endl<<endl;
     
    cout<<"1) \t\t 2) \t\t 3)"<<endl;
    cout<<"P40 Pro \t P40 \t\t y7p"<<endl;
    cout<<"Precio: $1099 \t Precio: $865 \t Precio: $239"<<endl<<endl;

    cout<<"4) \t\t 5) \t\t 6)"<<endl;
    cout<<"y8p \t\t MediaPad T3 \t Watch GT 2e"<<endl;
    cout<<"Precio: $299 \t Precio: $130 \t Precio: $210"<<endl<<endl;

    cout<<"7) \t\t 8) \t\t 9)"<<endl;
    cout<<"Matebook D14 \t Matebook D15 \t FreeBuds3"<<endl;
    cout<<"Precio: $749 \t Precio: $830 \t Precio: $137"<<endl<<endl;

    cout<<"10) Regresar"<<endl;

    cout<<"Ingresa la opcion que deseas:";
    cin>>opcion; cin.ignore();
    
    

    return opcion;

}
void Agregar_clientes3(queue<cliente>&local3){
    cliente nuevoCliente;
    int opcion;
    bool continuar=true;

    cout<<"Ingrese su nombre y apellido: ";
    getline(cin,nuevoCliente.nombre);

    do{
    opcion=menu_local3();

        switch(opcion){

            case 1: nuevoCliente.compras.push_back(obtener_producto_local3(1)); break;
            case 2: nuevoCliente.compras.push_back(obtener_producto_local3(2)); break;
            case 3: nuevoCliente.compras.push_back(obtener_producto_local3(3)); break;
            case 4: nuevoCliente.compras.push_back(obtener_producto_local3(4)); break;
            case 5: nuevoCliente.compras.push_back(obtener_producto_local3(5)); break;
            case 6: nuevoCliente.compras.push_back(obtener_producto_local3(6)); break;
            case 7: nuevoCliente.compras.push_back(obtener_producto_local3(7)); break;
            case 8: nuevoCliente.compras.push_back(obtener_producto_local3(8)); break;
            case 9: nuevoCliente.compras.push_back(obtener_producto_local3(9)); break;
            case 10: continuar=false; break;
            default: cout<<"opcion no valida."<<endl;
        }
    }while(continuar);
    local3.push(nuevoCliente);
}

producto obtener_producto_local3(int opcion){
    producto nuevoProducto;
    switch(opcion){
        case 1: nuevoProducto.name = "P40 Pro";
                nuevoProducto.precio_unitario = 1099;
                break;

        case 2: nuevoProducto.name = "P40"; 
                nuevoProducto.precio_unitario = 865;
                break;
                
        case 3: nuevoProducto.name = "y7p";
                nuevoProducto.precio_unitario = 239;
                break;
                
        case 4: nuevoProducto.name = "y8p";
                nuevoProducto.precio_unitario = 299;
                break;
                
        case 5: nuevoProducto.name = "MediaPad T3";
                nuevoProducto.precio_unitario = 130;
                break;
        
        case 6: nuevoProducto.name = "Watch GT 2e";
                nuevoProducto.precio_unitario = 210;
                break;
                
        case 7: nuevoProducto.name = "Matebook D14";
                nuevoProducto.precio_unitario = 749;
                break;
                
        case 8: nuevoProducto.name = "Matebook D15";
                nuevoProducto.precio_unitario = 830;
                break;
                
        case 9: nuevoProducto.name = "FreeBuds3";
                nuevoProducto.precio_unitario = 137;
                break;
    }
    return nuevoProducto;
}

void mostrar_clientes(queue<cliente>&Local){

queue<cliente>Localx=Local;
vector<producto>copia;
    
    while(!Localx.empty()){
        cout <<"Nombre: "<<Localx.front().nombre<<endl<<endl;
        cout<<"Carrito de compras"<<endl<<endl;
        copia=Localx.front().compras;
        for(int pos=0;pos<copia.size();pos++){
        cout <<"   "<<copia[pos].name<<endl;
        cout <<"   Precio: $"<<copia[pos].precio_unitario<<endl<<endl;}
        Localx.pop();
    }
    }


void Mayor_venta(queue<cliente>&Local1,queue<cliente>&Local2,queue<cliente>&Local3){
    float montoLocal1 = monto(Local1);
    float montoLocal2 = monto(Local2);
    float montoLocal3 = monto(Local3);
    int indicador = 1;
    
    if(montoLocal1<montoLocal2){
        indicador = 2;
        if(montoLocal2<montoLocal3){
            indicador = 3;
        }
    }else if(montoLocal1<montoLocal3){
        indicador = 3;
    }
    
    if(indicador == 1){
        cout<<"El local con mas ventas es Samsung"<<endl;
        cout<<"Con un total de: $"<<montoLocal1<<endl;
    }else if(indicador == 2){
        cout<<"El local con mas ventas es Apple"<<endl;
        cout<<"Con un total de: $"<<montoLocal2<<endl;
    }else if(indicador == 3){
        cout<<"El local con mas ventas es Huawei"<<endl;
        cout<<"Con un total de: $"<<montoLocal3<<endl;
    }
}