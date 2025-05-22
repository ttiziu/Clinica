#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

#define MAXPAC 100
#define MAXMED 13
#define MAXCIT 100
#define MAXATN 100
struct paciente
{
	string nombrep;
	string apellidop;
	int dni;
};
struct medico
{
	string nombrem;
	string apellidom;
	string especialidad;
	int ncolegiatura;
	int honorario;
};
struct cita
{
	int hora;
	int fecha;
	string dia;
};
struct atencion
{
	int  respuesta;
	int medicamento;
};
void limpiarpantalla()
{
	system("cls");

}
void menu()
{
	int mat[21][70] =
	{ {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,3,1,1,1,1,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,3,3,3,1,1,1,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,3,1,1,1,1,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	limpiarpantalla();

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			if (mat[i][j] == 0)
			{
				// Color omitido = // ColorBlack;
				cout << ' ';
			}
			if (mat[i][j] == 1)
			{
				// Color omitido = // ColorWhite;
				cout << (char)219;
			}
			if (mat[i][j] == 2)
			{
				// Color omitido = // ColorDarkCyan;
				cout << (char)219;
			}
			if (mat[i][j] == 3)
			{
				// Color omitido = // ColorDarkRed;
				cout << (char)219;
			}
		}
		cout << endl;
		// Color omitido = // ColorBlack;
	}
}
void reporte4(paciente* vpaciente, int npac, medico* vmedico, int nmed, cita* vcitas, int ncitas)
{
	string nombrem, dia;
	cout << "Ingrese el nombre del medico: " << endl;
	cin >> nombrem;
	cout << "\tIngrese el dia a ver: " << endl;
	cout << "\tLunes - Martes - Miercoles - Jueves - Viernes - Sabado " << endl;
	cin >> dia;
	cout << "NOMBRE " << '/t' << "APELLIDO" << '/t' << "HORA" << endl;
	for (int i = 0; i < nmed; i++)
	{
		if (nombrem == vmedico[i].nombrem) {
			if (dia == vcitas[i].dia) {
				cout << vpaciente[i].nombrep << vpaciente[i].apellidop << vcitas[i].hora << endl;
			}
		}
	}
}
void reporte3(paciente* vpaciente, int npac, medico* vmedico, int nmed, cita* vcitas, int ncitas)
{
	string nombre, apellido;
	int aux, j, contador = 0;
	cout << "Ingrese el nombre y apellido del medico: " << endl;
	cin >> nombre >> apellido;

	cout << endl << "DNI:  " << '\t' << '\t' << "NOMBRE:" << '\t' << '\t' << "APELLIDO:" << endl;
	for (int i = 0; i < npac; i++)
	{
		if (nombre == vmedico[i].nombrem)
		{
			j = 1;
			if (vpaciente[i].dni < vpaciente[j].dni) {
				aux = vpaciente[i].dni;
				vpaciente[i].dni = vpaciente[j].dni;
				vpaciente[j].dni = aux;
			}

			cout << vpaciente[i].dni << '\t' << vpaciente[i].nombrep << '\t' << '\t' << vpaciente[i].apellidop << endl;

			contador += 1;
		}
	}
	if (contador == 0) {
		cout << "Medico no encontrado, vuelva a intentarlo";
	}


}
void reporte2(paciente* vpaciente, int npac, medico* vmedico, int nmed, cita* vcitas, int ncitas, atencion* vatenciones)
{
	int validar = 0;
	int dni;
	cout << "Ingrese DNI del paciente (8 digitos): " << endl;
	cin >> dni;
	for (int i = 0; i < npac; i++)
	{
		if (dni == vpaciente[i].dni)
		{
			cout << "El paciente " << vpaciente[i].nombrep << ' ' << vpaciente[i].apellidop << " fue atendido por el medico " << vmedico[i].nombrem << " especializado en " << vmedico[i].especialidad << endl;
			cout << "Se encotraba enfermo al comienzo?   ";
			if (vatenciones[i].respuesta == 1) {
				cout << "si " << endl;
			}
			else {
				cout << " no" << endl;
			}
			cout << "Recomendacion del doctor: ";
			cout << vatenciones[i].medicamento;
			switch (vatenciones[i].medicamento)
			{
			case 1: cout << "1. pastilla" << endl; break;
			case 2:	cout << "2. cirugia u operación" << endl; break;
			case 3:	cout << "3. inyectable " << endl; break;
			case 4:	cout << "4. Jarabe" << endl; break;
			case 5:	cout << "5. Analisis de sangre" << endl; break;
			case 6:	cout << "6. Examen de orina" << endl; break;
			case 7:	cout << "7. Ecografica// Radiografia// Tomografia" << endl; break;
			case 8:	cout << "8. Se va a psicologia" << endl; break;
			}
			validar = 0;
			break;
		}
		else
		{
			validar = 1;
		}
	}
	if (validar == 1)
	{
		cout << "El paciente que ingreso no fue antendido en esta clinica. " << endl;
	}
}
void reporte1(medico* vmedico, int nmed, cita* vcitas, int ncitas)
{
	int suma = 0;
	for (int i = 0; i < ncitas; i++)
	{
		suma = suma + vmedico[i].honorario;
	}
	for (int i = 0; i < ncitas; i++)
	{
		cout << "RECAUDACION DIARIA: " << endl << "Suma de todas las reservas hechas: " << suma << " nuevos soles.";
	}
}
void menu_de_reportes(medico* vmedico, int nmed, paciente* vpaciente, int npac, cita* vcitas, int ncitas, atencion* vatenciones, int naten)
{
	string y = "Presiona cualquier tecla para volver ... ";
	int opc;
	do
	{
		system("cls");
		cout << "\t------------------- MENU REPORTES -------------------" << endl;
		cout << "\t1. Reporte de recaudacion diaria: El total del monto recaudado diariamente. " << endl;
		cout << "\t2. Reporte de atenciones del paciente segun su DNI. " << endl;
		cout << "\t3. Reporte de pacientes atendidos por un determinado medico, ordenado de forma ascendente por DNI. " << endl;
		cout << "\t4. Reporte de citas para un medico en una fecha especifica. " << endl;
		cout << "\t5. Ordenar de forma ascendente la reserva de citas" << endl;
		cout << "\t6. Retorna al menu.";
		do
		{
			cout << "\033[17,5H";
			cout << "Ingresar opcion: ";
			cin >> opc;
		} while (opc < 1 || opc>5);
		if (opc != 5)
		{
			switch (opc)
			{
			case 1:
				system("cls");
				reporte1(vmedico, nmed, vcitas, ncitas);
				cout << "\033[10,1H";
				cout << y;
				_getch();
				break;

			case 2:
				system("cls");
				reporte2(vpaciente, npac, vmedico, nmed, vcitas, ncitas, vatenciones);
				cout << "\033[25,1H";
				cout << y;
				_getch();
				break;

			case 3:
				system("cls");
				reporte3(vpaciente, npac, vmedico, nmed, vcitas, ncitas);
				cout << "\033[25,1H";
				cout << y;

				_getch();
				break;
			case 4:
				system("cls");
				reporte4(vpaciente, npac, vmedico, nmed, vcitas, ncitas);
				cout << "\033[70,1H";
				cout << y;
				_getch();
				break;
			}// FIN DEL switch
		}// FIN DEL if
	} while ((opc != 5));// FIN do{}while
}
int registro_atencion(medico* vmedico, int nmed, paciente* vpaciente, int npac, cita* vcitas, int ncitas, atencion* vatenciones, int naten)
{

	cout << "------------	INGRESE PACIENTE ATENDIDO ---------------" << endl;
	cout << "Ingrese su Numero de colegiatura: ";
	cin >> vmedico[nmed].ncolegiatura;
	cout << "Ingrese DNI del paciente recibido: ";
	cin >> vpaciente[npac].dni;
	cout << "El paciente que atendio se encuentra enfermo: Si (1)  || No (2) ";
	cin >> vatenciones[naten].respuesta;
	if (vatenciones[naten].respuesta == 1) {
		cout << endl << "Ingrese el procedimiento a tratar: " << endl;
		cout << "1. pastilla" << endl;
		cout << "2. cirugia u operación" << endl;
		cout << "3. inyectable " << endl;
		cout << "4. Jarabe" << endl;
		cout << "5. Analisis de sangre" << endl;
		cout << "6. Examen de orina" << endl;
		cout << "7. Ecografica// Radiografia// Tomografia" << endl;
		cout << "8. Se va a psicologia" << endl;
		cin >> vatenciones[naten].medicamento;
	}
	else {
		cout << endl << " Paciente en buen estado de salud.";
	}
	naten++;
	return naten;

}
int reservar_cita(medico* vmedico, int nmed, paciente* vpaciente, int npac, cita* vcitas, int ncitas)// LISTO Y EJECUTABLE
{
	string especialidad;
	string nombre;
	int validarM = 0, validarP = 0, validarC = 0;
	cout << '\t' << "---------- RESERVA TU CITA CON TU MEDICO----------" << endl;
	cout << "\t1. Odontologia" << endl;
	cout << "\t2. Cardiologia" << endl;
	cout << "\t3. Oftalmologia" << endl;
	cout << "\t4. Dermatologia" << endl;
	cout << "\t5. Neurologia" << endl;
	cout << "\t6. Mastologia" << endl;
	cout << "\t7. Gastroenterologia" << endl;
	cout << "\t8. Neurologia" << endl;
	cout << "\t9. Urologia" << endl;
	cout << "\t10. Hematologia" << endl;
	cout << "\tIngrese la especialidad ";
	cin >> especialidad;
	cout << "\tMedicos\tHonorarios " << endl;
	for (int i = 0; i < nmed; i++)
	{
		if (especialidad == vmedico[i].especialidad)
		{
			cout << '\t' << vmedico[i].nombrem << ' ' << vmedico[i].apellidom << " (S/" << vmedico[i].honorario << ") nuevos soles" << endl;
		}
	}
	cout << "\tIngrese el primer nombre del medico que guste escoger: ";
	cin >> vmedico[nmed].nombrem;
	cout << "\tIngrese el primer apellido del medico: ";
	cin >> vmedico[nmed].apellidom;

	cout << "\tIngresa tu DNI ya registrado como paciente (8 digitos): ";
	cin >> vpaciente[npac].dni;

	for (int i = 0; i < npac; i++)
	{
		if (vpaciente[npac].dni == vpaciente[i].dni)
		{
			cout << endl << "Paciente: " << vpaciente[i].nombrep << ' ' << vpaciente[i].apellidop;
			validarP = 0;
			break;
		}
		else
		{
			validarP = 1;
		}
	}
	if (validarP == 1)
	{
		cout << endl << "El paciente que ingreso no esta registrado porfavor intente con otro. " << endl;
	}
	if (validarP != 1)
	{
		cout << endl << " Lunes - Martes - Miercoles - Jueves - Sabado - Domingo " << endl;
		cout << endl << "Ingrese el dia que desee usted ser atendido: ";
		cin >> vcitas[ncitas].dia;
		do
		{
			cout << "Ingrese la hora que guste usted ser atendido (12 - 22) pm : ";
			cin >> vcitas[ncitas].hora;
		} while (vcitas[ncitas].hora < 12 || vcitas[ncitas].hora>22);

		for (int i = 0; i < ncitas; i++)
		{
			if (vcitas[ncitas].dia == vcitas[i].dia && vcitas[ncitas].hora == vcitas[i].hora && vpaciente[npac].dni == vpaciente[i].dni || vcitas[ncitas].hora == vcitas[i].hora && vmedico[nmed].especialidad == vmedico[nmed].especialidad && vpaciente[npac].dni != vpaciente[i].dni)
			{
				cout << endl << "RESERVA NO DISPONIBLE INGRESE OTRA FECHA Y HORA";
				validarC = 1;
				break;
			}
		}
		if (validarC != 1)
		{
			cout << endl << "Cita reservada para el dia " << vcitas[ncitas].dia << " a las " << vcitas[ncitas].hora << ":00 pm" << endl;
			ncitas++;
		}
	}
	return ncitas;
}
void imprimir_medicos_registrados(medico* vmedico, int nmed)
{
	cout << "\t---------- MEDICOS REGISTRADOS ----------" << endl;
	for (int i = 0; i < nmed; i++)

		cout << "Medico " << i + 1 << ": " << endl
		<< "\tNombre: " << vmedico[i].nombrem << endl
		<< "\tApellido: " << vmedico[i].apellidom << endl
		<< "\tEspecialidad: " << vmedico[i].especialidad << endl
		<< "\tHonorario: " << "(S/ " << vmedico[i].honorario << ")" << endl
		<< "\tNcolegiatura: " << vmedico[i].ncolegiatura << endl;
}
int registrar_medico(medico* vmedico, int nmed)//  LISTO Y EJECUTBALE
{
	do
	{
		cout << "Ingrese colegiatura (6 digitos): " << endl;
		cin >> vmedico[nmed].ncolegiatura;
	} while (vmedico[nmed].ncolegiatura < 100000 || vmedico[nmed].ncolegiatura>999999);
	cout << "Ingrese nombre y apellido: " << endl;
	cin >> vmedico[nmed].nombrem >> vmedico[nmed].apellidom;
	cout << "Ingrese especialidad: " << endl;
	cin >> vmedico[nmed].especialidad;
	cout << "Ingrese honorario de su reserva de cita : " << endl;
	cin >> vmedico[nmed].honorario;

	cout << endl << "---------- MEDICO REGISTRADO ----------" << endl;

	cout << "Medico " << vmedico[nmed].nombrem << ' ' << vmedico[nmed].apellidom << " que se especializa en " << vmedico[nmed].especialidad << endl;
	cout << "Honorario de: " << "(S/" << vmedico[nmed].honorario << ")" << endl;

	nmed++;
	return nmed;
}
void imprimir_pacientes_registrados(paciente* vpaciente, int npac)
{
	cout << '\t' << "    \tNombres" << '\t' << "Apellidos" << '\t' << "DNIs" << endl;
	for (int i = 0; i < npac; i++)
		cout << "Paciente " << i + 1 << ": "
		<< vpaciente[i].nombrep << '\t'
		<< vpaciente[i].apellidop << '\t' << '\t'
		<< vpaciente[i].dni << endl;
}
int registrar_paciente(paciente* vpaciente, int npac)// LISTO Y EJECUTABLE
{
	do
	{
		cout << "Ingrese su DNI (8 digitos): " << endl;
		cin >> vpaciente[npac].dni;
	} while (vpaciente[npac].dni < 10000000 || vpaciente[npac].dni>99999999);
	cout << "Ingrese nombre y apellido: " << endl;
	cin >> vpaciente[npac].nombrep >> vpaciente[npac].apellidop;
	cout << endl;
	cout << "DNI: " << vpaciente[npac].dni << '\t' << "Paciente: " << vpaciente[npac].nombrep << ' ' << vpaciente[npac].apellidop << endl;
	npac++;
	return npac;
}
void main()
{
	paciente* vpaciente = new paciente[MAXPAC];
	int npac = 10;
	vpaciente[0].nombrep = "Jherry";
	vpaciente[0].apellidop = "Visalot";
	vpaciente[0].dni = 77069245;

	vpaciente[1].nombrep = "Lucero";
	vpaciente[1].apellidop = "Vargas";
	vpaciente[1].dni = 71021728;

	vpaciente[2].nombrep = "Doria";
	vpaciente[2].apellidop = "Campoverde";
	vpaciente[2].dni = 14231212;

	vpaciente[3].nombrep = "Gilberto";
	vpaciente[3].apellidop = "Merino";
	vpaciente[3].dni = 14323122;

	vpaciente[4].nombrep = "Daniel";
	vpaciente[4].apellidop = "Vasquez";
	vpaciente[4].dni = 77043238;

	vpaciente[5].nombrep = "Stephano";
	vpaciente[5].apellidop = "Navarro";
	vpaciente[5].dni = 77182731;

	vpaciente[6].nombrep = "Briana";
	vpaciente[6].apellidop = "Sanchez";
	vpaciente[6].dni = 34862632;

	vpaciente[7].nombrep = "Celina";
	vpaciente[7].apellidop = "Vasquez";
	vpaciente[7].dni = 45848209;

	vpaciente[8].nombrep = "Richard";
	vpaciente[8].apellidop = "Novoa";
	vpaciente[8].dni = 56048382;

	vpaciente[9].nombrep = "Luis";
	vpaciente[9].apellidop = "Barrantes";
	vpaciente[9].dni = 38292010;

	medico* vmedico = new medico[MAXMED];
	int nmed = 10;
	vmedico[0].nombrem = "Hugo";
	vmedico[0].apellidom = "Maslucan";
	vmedico[0].especialidad = "Odontologia";
	vmedico[0].ncolegiatura = 111111;
	vmedico[0].honorario = 1230;

	vmedico[1].nombrem = "Jose";
	vmedico[1].apellidom = "Pardo";
	vmedico[1].especialidad = "Cardiologia";
	vmedico[1].ncolegiatura = 777777;
	vmedico[1].honorario = 893;

	vmedico[2].nombrem = "Mariabelen";
	vmedico[2].apellidom = "Solano";
	vmedico[2].especialidad = "Oftalmologia";
	vmedico[2].ncolegiatura = 556555;
	vmedico[2].honorario = 543;

	vmedico[3].nombrem = "Claudio";
	vmedico[3].apellidom = "Pizarro";
	vmedico[3].especialidad = "Dermatologia";
	vmedico[3].ncolegiatura = 898888;
	vmedico[3].honorario = 1234;

	vmedico[4].nombrem = "Martin";
	vmedico[4].apellidom = "Loayza";
	vmedico[4].especialidad = "Neurologia";
	vmedico[4].ncolegiatura = 667666;
	vmedico[4].honorario = 989;

	vmedico[5].nombrem = "Mateo";
	vmedico[5].apellidom = "Vizcarra";
	vmedico[5].especialidad = "Mastologia";
	vmedico[5].ncolegiatura = 545454;
	vmedico[5].honorario = 764;

	vmedico[6].nombrem = "Juan";
	vmedico[6].apellidom = "Vidal";
	vmedico[6].especialidad = "Gastroenterologia";
	vmedico[6].ncolegiatura = 897889;
	vmedico[6].honorario = 1234;

	vmedico[7].nombrem = "Alejandro";
	vmedico[7].apellidom = "Merino";
	vmedico[7].especialidad = "Neurologia";
	vmedico[7].ncolegiatura = 445444;
	vmedico[7].honorario = 983;

	vmedico[8].nombrem = "Juan";
	vmedico[8].apellidom = "Quispe";
	vmedico[8].especialidad = "Urologia";
	vmedico[8].ncolegiatura = 743374;
	vmedico[8].honorario = 765;

	vmedico[9].nombrem = "Ariana";
	vmedico[9].apellidom = "Campos";
	vmedico[9].especialidad = "Hematologia";
	vmedico[9].ncolegiatura = 223222;
	vmedico[9].honorario = 467;

	cita* vcitas = new cita[MAXCIT];
	int ncitas = 0;
	atencion* vatenciones = new atencion[MAXATN];
	int naten = 0;
	string x = "Has sido regitrado ... ";
	string y = "Presiona cualquier tecla para volver ... ";
	int opc;
	do
	{
		system("cls");
		menu();
		cout << "\033[3,5H";
		cout << "------------------- MENU CLINICA -------------------" << endl;
		cout << "\033[5,5H";
		cout << "1. Registrar Paciente " << endl;
		cout << "\033[6,5H";
		cout << "2. Mostrar Pacientes " << endl;
		cout << "\033[7,5H";
		cout << "3. Registrar Medico " << endl;
		cout << "\033[8,5H";
		cout << "4. Mostrar Medicos " << endl;
		cout << "\033[9,5H";
		cout << "5. Reservar Cita " << endl;
		cout << "\033[10,5H";
		cout << "6. Registro de atencion " << endl;
		cout << "\033[11,5H";
		cout << "7. Creditos " << endl;
		cout << "\033[12,5H";
		cout << "8. REPORTES " << endl;
		cout << "\033[13,5H";
		cout << "9. Salir " << endl;
		cout << "\033[15,5H";
		do
		{
			cout << "\033[17,5H";
			cout << "Ingresar opcion: ";
			cin >> opc;
		} while (opc < 1 || opc>9);
		if (opc != 9)
		{
			switch (opc)
			{
			case 1:
				limpiarpantalla();
				npac = registrar_paciente(vpaciente, npac);
				cout << endl << x << endl;
				cout << "\033[25,1H";
				cout << y;
				_getch();
				break;

			case 2:
				limpiarpantalla();
				imprimir_pacientes_registrados(vpaciente, npac);
				cout << "\033[25,1H";
				cout << y;
				_getch();
				break;

			case 3:
				limpiarpantalla();
				nmed = registrar_medico(vmedico, nmed);
				cout << endl << x << endl;
				cout << "\033[25,1H";
				cout << y;

				_getch();
				break;
			case 4:
				limpiarpantalla();
				imprimir_medicos_registrados(vmedico, nmed);
				cout << "\033[70,1H";
				cout << y;
				_getch();
				break;
			case 5:

				limpiarpantalla();
				ncitas = reservar_cita(vmedico, nmed, vpaciente, npac, vcitas, ncitas);
				cout << "\033[25,1H";
				cout << y;
				_getch();
				break;
			case 6:
				limpiarpantalla();
				naten = registro_atencion(vmedico, nmed, vpaciente, npac, vcitas, ncitas, vatenciones, naten);
				cout << "\033[26,1H";
				cout << y;
				_getch();
				break;
			case 7:
				limpiarpantalla();
				cout << "\033[2,2H";
				// Color omitido = // ColorYellow;
				cout << "   _ _      _ _   _       _ __  _   _ " << endl;
				cout << "  / | |    |   | \\ | |   /\\|   _/ _ \\| \\ | |" << endl;
				cout << " | |  | |      | | |  \\| |  /  \\  | | | |  | |  \\| |" << endl;
				cout << " | |     | |      | | | . ` | / /\\ \\ | | | |  | | . ` |" << endl;
				cout << " | ||   | | || |\\  |/ _ \\| | | |_| | |\\  |" << endl;
				cout << " \\| _||| \\//    \\||  \\/|| \\|" << endl;
				cout << "CREDITOS: " << endl;
				cout << "\033[10,0H";
				cout << " - Campos Trinidad, Ariana Ivonne (U202218988)" << endl;
				cout << " - Vargas Paucca, Lucero Belen (U202215301)" << endl;
				cout << " - Visalot Giron, Jherry Paolo (U202218342)" << endl;
				cout << "\033[14,1H";
				// Color omitido = // ColorDarkYellow;
				cout << y;
				_getch();
				break;
			case 8:
				limpiarpantalla();
				menu_de_reportes(vmedico, nmed, vpaciente, npac, vcitas, ncitas, vatenciones, naten);
			}// FIN DEL switch
		}// FIN DEL if
	} while ((opc != 9));// FIN do{}while
	delete[]vpaciente;
	delete[]vmedico;
	delete[]vcitas;
}// FIN DEL void main