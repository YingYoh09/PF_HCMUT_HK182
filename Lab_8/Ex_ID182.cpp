
Student binRead(const char *fileName)
{
    fstream ifs;
    ifs.open(fileName, ios::in | ios::binary);
    if (ifs.fail())
        throw "File not found.";
    int id;
    int nameLen;
    float gpa;
    char *name;
    ifs.read((char *)&id, sizeof(int));
    ifs.read((char *)&nameLen, sizeof(int));
    name = new char[nameLen + 1];
    ifs.read(name, nameLen * sizeof(char));
    name[nameLen] = '\0';
    ifs.read((char *)&gpa, sizeof(float));
    ifs.close();
    Student res(id, name, gpa);
    delete[] name;
    return res;
}