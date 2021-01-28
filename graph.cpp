// メインファイル
#include <iostream>
#include <string>
#include <map>
#include <vector>

#define Tree 0
#define nondirected 2
bool tree = true;
bool directed = false; 
int root = 1e9; // 根として扱う頂点
bool content = false; // 重み付きかどうか
using namespace std;
vector<pair<int,int>> edge_set(0);
vector<int> value(0);
void input_edge(string type){
	int tp = stoi(type);
	if(content){
		cerr  <<"重みあり" << endl;
	} else {
		cerr <<"重みなし" << endl;
	}
	if(tp == 0){
		cerr << "通常形式の入力" << endl;
		int n;
		cin >>  n;
		int m;
		if(tree){
			m = n - 1;
		} else {
			cin >> m;
		}
		for(int i = 0; i < m; i++){
			int x, y;
			cin >>  x >> y;
			if(content){
				int c;
				cin >>  c;
				value.push_back(c);
			}
			edge_set.push_back({x,y});
		}
	} else {
		cerr << "行列形式の入力" << endl;
		// 行列形式での入力
		int n;
		cin >>  n;
		map<pair<int,int>, bool> mp;
		for(int i = 0; i < n; i++){
			for(int j = 0;j < n; j++){
				// 無向グラフのときに,2回同じ辺を受け取らないようにする
				if(content){
					//intで受け取る
					int now;
					cin >>  now;
					if(now){
						// != 0
						if(j > i) swap(i,j);
						if(mp[{i,j}]) continue;
						mp[{i,j}] = true;
						edge_set.push_back({i,j});
						value.push_back(now);
					}
				} else { // 重みなし
					char is;
					cin >>  is;
					int now = (is - '0');
					if(now){
						if(j < i){
							if(mp[{j,i}]) continue;
						}
						mp[{i,j}] = true;
						edge_set.push_back({i,j});
					} 
				}
			}
		}
	}
}
string make_edge(){
	string ret = "{";
	int m = edge_set.size();
	for(int i = 0; i < m; i++){
		int x, y;
		tie(x,y) = edge_set[i];
		if(i) ret += ", ";
		string add = "";
		if(content) add += "{";
		add += to_string(x);
		add += " -> ";
		add += to_string(y);
		// {3 -> 6, "content"} 
		// 3 -> 6
		if(content) {
			add += ", \"" + to_string(value[i]) + "\"}";
		}
		ret += add;
	}
	ret += "}";
	return ret;
}

string get_type(string type){
	string ret = "";
	int tp = stoi(type);
	if(tp == 0){
		cerr << "木" << endl;
		tree = true;
		directed = false;
		ret = "TreePlot";
	} else if (tp == 1){
		ret = "GraphPlot";
		directed = false;
		tree = false;
		cerr << "無向グラフ" << endl;
	} else if (tp == 2){
		ret = "GraphPlot";
		tree = false;
		directed = true;
		cerr << "有向グラフ" << endl;
	}
	return ret;
}

void mkroot(){
	for(auto x:edge_set){
		root = min(root,x.first);
		root = min(root,x.second);
	}
	return ;
}
int main(int argc, char *argv[])
{
	cerr <<"形式指定は./a.out以降に.\n 重み有無, 木・無向・有向, 入力は通常(0)行列(1), 根の指定 だよ" << endl;
	string type_index = "0";
	string edge_index = "0";
	if(argc >= 2){
		//重み
		if(stoi(argv[1])) content = true;
		if(argc >= 3){
			// グラフの形
			type_index = argv[2];
		}
		if(argc >= 4){
			// 入力形式
			edge_index = argv[3];
		}
	}
	string type = get_type(type_index);

	if(tree){
		if(argc >= 5){
			// 根の値を指定するかどうか
			int tmp = stoi(argv[4]);
			root = tmp;
			cerr << "根: " << root << endl;
		} else {
			cerr << "根: 指定なし" << endl;
		}
	}

	input_edge(edge_index);
	string g = make_edge();
	string setting = ",VertexLabeling -> True";

	if(root == 1e9){
		mkroot();// ルートを存在する値に設定する
	}
	if(directed) setting += ", DirectedEdges -> True";
	setting += ", ImageSize -> Large";
	cout << type << "[" <<  g;
	if(tree) cout << ", " << root;
	cout << setting <<"]" << endl;
	
}
