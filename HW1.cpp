#include <iostream>
#include <string>
using namespace std;


int main(){
	int taskNum = 0;
	string task[100][100];
	int N = 2;
	taskNum = 2;

	cout << "Enter number of Task: " ;
	cin >> taskNum;

	cout << "Enter number of Task Segment(N) : " ;
	cin >> N;

	string pro = "1001" ; // 0 denotes IO
	

	for( int i = 0 ; i < taskNum ; i++ ){
		for( int j = 0 ; j < N ; j++ ){
			task[i][j] = pro;
		}
	}

cout <<endl <<"0 denotes IO and 1 denotes CPU"<< endl;
	
	int cpu , IO , changeTask;
	int go = 1;
	int gos = 3;
	int num = 0;
	int CpuDoesntWork = 0;
	while( go ){
		num++;
		cpu = IO = 0;
//CPU
		for( int i = 0 ; i < taskNum && !cpu ; i++ ){
			changeTask = 0;
			for( int j = 0 ; j < N && !cpu && !changeTask ; j++ ){
				for( int k = 0 ; k <  task[i][j].size() ; k++ ){
					if( task[i][j][k] == '0' ){
							changeTask = 1;
							break;
					}
					if( task[i][j][k] == '1' ){
						cpu = i+1;
						task[i][j][k] = 'X' ;
						changeTask = 1;
						break;
					}
				}
			}
		}
		if( cpu == 0 )
			CpuDoesntWork++;
//IO
		for( int i = 0 ; i < taskNum && !IO ; i++ ){
			if( cpu-1 == i )
				continue;
			changeTask = 0;
			for( int j = 0 ; j < N && !IO && !changeTask ; j++ ){
				for( int k = 0 ; k <  task[i][j].size() ; k++ ){
					if( task[i][j][k] == '1' ){
							changeTask = 1;
							break;
					}
					if( task[i][j][k] == '0' ){
						IO = 1;
						task[i][j][k] = 'X' ;
						break;
					}
				}
			}
		}

// Break check
		go = 0;
		cout << "Proccess of step "<<num<<" is:"<< endl;
		for( int i = 0 ; i < taskNum ; i++ ){
			changeTask = 0;
			cout <<"#"<<i+1 <<" ";
			for( int j = 0 ; j < N ; j++ ){
					cout <<task[i][j] << "  ";
				for( int k = 0 ; k <  task[i][j].size() ; k++ ){
					if( task[i][j][k] == '0' || task[i][j][k] == '1' ){
							go = 1;
							break;
					}
				}
			}
	cout << endl;
		}
cout << endl;
	}

	float cpuF = 1 - (CpuDoesntWork)/(num+0.0) ;
	float power = taskNum/(num+0.0);
	cout << "CPU performance: " << cpuF*100 << "%" << endl;
	cout << "Throughput: " << power*4 << endl; 
	return 0;
}


