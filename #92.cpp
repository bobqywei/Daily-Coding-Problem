#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> *traverse_courses(string curr, unordered_map<string, vector<string>*> &prereqs, vector<string> &sequence, int num_courses) {
	if (sequence.size() == num_courses) {
		vector<string> *ret = new vector<string>;
		*ret = sequence;
		return ret;
	}

	vector<string> *curr_prereqs = prereqs[curr];

	for (string course : *curr_prereqs) {
		vector<string> temp;
		temp = sequence;
		temp.push_back(course);

		vector<string> *ret = traverse_courses(course, prereqs, temp, num_courses);
		
		if (ret != nullptr) return ret;
	}

	return nullptr;
}

vector<string> *get_course_sequence(unordered_map<string, vector<string>*> &prereqs) {
	int num_courses = prereqs.size();

	for (pair<string, vector<string>*> p : prereqs) {
		vector<string> temp;
		temp.push_back(p.first);
		vector<string> *ret = traverse_courses(p.first, prereqs, temp, num_courses);

		if (ret != nullptr) return ret;
	}

	return nullptr;
}

int main() {
	unordered_map<string, vector<string> *> prereqs;
	prereqs["CSC300"] = new vector<string>;
	prereqs["CSC200"] = new vector<string>;
	prereqs["CSC100"] = new vector<string>;

	prereqs["CSC300"]->push_back("CSC100");
	prereqs["CSC300"]->push_back("CSC200");
	prereqs["CSC200"]->push_back("CSC100");

	vector<string> *sequence = get_course_sequence(prereqs);

	if (sequence == nullptr) 
		cout << "No possible sequence including all " << prereqs.size() << " courses." << endl;
	else {
		for (int i = sequence->size()-1; i >= 0; i--) {
			cout << (*sequence)[i];
			if (i != 0) cout << " -> "; 
		}
		cout << endl;
	}
}