#pragma once

#include <string>

/// <summary>
/// �����һ���ڵ��е�����
/// </summary>
struct Data
{
    std::string name;
    std::string brand;
    double price;
    int count;
};

/// <summary>
/// �����һ���ڵ�
/// </summary>
struct Cell
{
    struct Data data;
    struct Cell* next;
};

/// <summary>
/// ����һ��������
/// </summary>
/// <returns>��������ͷ�ڵ�</returns>
inline Cell* InitList()
{
    Cell* head = new Cell;

    head->data.name = "";
    head->data.brand = "";
    head->data.price = 0;
    head->data.count = 0;
    head->next = nullptr;

    return head;
}

/// <summary>
/// ������ָ��λ�õĺ�߲���һ���ڵ�
/// </summary>
/// <param name="insertPosition">������ڵ��λ��</param>
/// <param name="insertData">�����������</param>
/// <returns>���ر�����Ľڵ�</returns>
inline Cell* Insert(Cell* insertPosition, Data insertData)
{
    Cell* insertCell = new Cell;

    insertCell->data = insertData;
    insertCell->next = insertPosition->next;
    insertPosition->next = insertCell;

    return insertCell;
}

/// <summary>
/// ������ָ��λ�õĺ��ɾ��һ���ڵ�
/// </summary>
/// <param name="deletePosition">��ɾ���ڵ��λ��</param>
/// <returns>���ر�ɾ���ڵ�ǰ�ߵĽڵ�</returns>
inline Cell* Delete(Cell* deletePosition)
{
    if (deletePosition->next != nullptr)
    {
        Cell* tempCell = deletePosition->next;
        deletePosition->next = tempCell->next;
        free(tempCell);

        return deletePosition;
    }
    return nullptr;
}

/// <summary>
/// ��������ָ��λ�õ�����
/// </summary>
/// <param name="updatePosition">���������ݵĽڵ�λ��</param>
/// <param name="updateData">�����µ�����</param>
/// <returns>���ر����µĽڵ�</returns>
inline void Update(Cell* updatePosition, Data updateData)
{
    // TODO ���Update

    return;
}

/// <summary>
/// ��ѯ��Ϣ�ķ�ʽ
/// </summary>
enum RETRIEVE_TYPE
{
    RETRIEVE_NAME,
    RETRIEVE_BRAND
};

/// <summary>
/// ��ѯ��������Ϣ������ѡ�����Ʋ��һ�Ʒ�Ʋ���
/// </summary>
/// <param name="strToFind">���ҵ��ַ���</param>
/// <param name="retrieveType">������Ϣ�ķ�ʽ
/// <para>��ΪRETRIEVE_NAME��������Ʒ���Ʋ���
/// <para>��ΪRETRIEVE_BRAND��������ƷƷ�Ʋ���
/// </param>
/// <returns>���ز��ҵ��ĵ�һ����Ʒ���ڽڵ�</returns>
inline Cell* Retrieve(std::string strToFind, enum RETRIEVE_TYPE retrieveType)
{
    // TODO ���Retrieve����vector�ȷ��ض��ֵ

    switch (retrieveType)
    {
    case RETRIEVE_NAME:
        break;
    case RETRIEVE_BRAND:
        break;
    }
    return nullptr;
}
