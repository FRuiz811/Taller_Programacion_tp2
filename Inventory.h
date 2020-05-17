#ifndef INVENTORY_H
#define INVENTORY_H
#include <mutex>
#include <condition_variable>
#include <unordered_map>

//La clase Inventory es donde se van a almacenan todos los recursos
//recolectados y que están esperando a que los productores los agarren
//y realicen puntos de beneficios con ellos. El inventario arranca como no 
//inicializado y vacio. Los recolectores serán los encargados de "abrirlo".
//Se realiza un control para que los recolectores y productores obtengan los
//recursos de manera ordenada, necesitan obtener el mutex para modificar el
//inventario.
class Inventory {
private:
	std::unordered_map<char,int> resources;
	std::mutex m;
    std::condition_variable cv;
    bool notified = false;
    bool not_initialize = true;
    bool farmers_finish = true;
    bool woodcutter_finish = true;
    bool miner_finish = true;

public:
	//Constructores para la clase Inventory, se permite el constructor
	//por movimiento, no asi por copia dado que no nos interesa que el 
	//inventory sea copiado ya que es único por Town.
	Inventory();
	Inventory(Inventory &&other);
    Inventory& operator=(Inventory&& other);

    //Se agrega una unidad del recurso ingresado como parámetro.
    //Si el recurso no es válido para este inventario, la función retorna
    //-1, en caso de éxito devuelve 0 y notifica a todos.
	int add_resource(const char resource);

	//Recibe como parámetro un pedido, que su clave es el recurso que deseado
	//y la cantidad necesaria del mismo. En caso de que esté disponible el 
	//inventario se verá si se tienen los recursos necesarios, si están serán
	//retirados. 
	//Retorna -1 en caso de que no estén los recursos solicitados, 1 en caso 
	//de que el inventario esté cerrado o no inicializdo, 0 en caso de que se
	//puedan retirar los recursos pedidos.
	int remove_resource(const std::unordered_map<char,int>& request);

	void print_resources() const;
	
	//Se utiliza para indicar que podrían llegar a ingresar recursos del tipo
	//indicado como parámetro.
	void initialize(const char resource);

	bool is_initialize() const;
	
	bool is_open() const;

	bool is_empty() const;
	
	//Indica que el recolector del recurso indicado como parámetro finalizó con
	//su trabajo.
	void collector_finish(const char type);

    ~Inventory();

	Inventory(const Inventory&) = delete;
    Inventory &operator=(const Inventory&) = delete;
};

#endif
