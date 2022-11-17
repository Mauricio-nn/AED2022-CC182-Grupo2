#pragma once
#include "Librerias.h"

using namespace std;
template<class T>
class AVLTree {
private:
    struct Node {
        T value;
        Node* leftChild;
        Node* rightChild;
        int height;//la altura del arbol
    };
    Node* _root;
    size_t _size;
    function<void(T)> _show;
    function<bool(T, T)> _compare;
private:
    void _insert(Node*& n, T value) {
        if (n == nullptr) {
            n = new Node{ value, nullptr, nullptr, 0 };
            ++_size;
            return;
        }
        if (_compare(n->value, value)) _insert(n->leftChild, value);
        else _insert(n->rightChild, value);
        _setHeight(n);//actualizamos altura luego de insertar
        _balanceSubTree(n);
    }
    void _preOrder(Node* n) {
        // if(n == nullptr) return;
        if (!n) return;
        _show(n->value); // 
        _preOrder(n->leftChild); // Izq
        _preOrder(n->rightChild); // Der
    }
    void _leftRotation(Node*& n) {//se usa el & porque se va a hacer un cambio en el node, por que ya no sera padre de
        //todos sino solo sera un hijo más y el hijo izquierdo pasara a ser padre
        Node* rightChild = n->rightChild;//rightchild va a ser igual al hijo derecho de n
        n->rightChild = rightChild->leftChild;// El hijo derecho del nodo apunta al hijo izquierdo del hijo derecho del nodo
        rightChild->leftChild = n;//el hijo derecho apunta al nodo n?
        _setHeight(n);
        _setHeight(rightChild);
        n = rightChild;//n ahora pasa a ser el hijo derecho
    }
    void _rightRotation(Node*& n) {
        Node* leftChild = n->leftChild;//leftchild va a ser igual al hijo izquierdo de n
        n->leftChild = leftChild->rightChild;//el hijo izquierdo apunta al hijo izquiero del hijo derecho del final
        leftChild->rightChild = n;//el hijo izquierdo apunta al nodo n?
        _setHeight(n);
        _setHeight(leftChild);
        n = leftChild;//n pasa a serl el hijo izquierdo
    }
    void _balanceSubTree(Node*& n) {
        int heightDifference = _getHeight(n->leftChild) - _getHeight(n->rightChild);
        if (heightDifference <= -2) {// Desbalanceado por la derecha
            if (n->rightChild->rightChild) {
                // Left rotation
                _leftRotation(n);
            }
            else {
                // Right-Left Rotation
                _rightRotation(n->rightChild);
                _leftRotation(n);
            }

        }
        else if (heightDifference >= 2) { // Desbalanceado por la izquierda
            if (n->leftChild->leftChild) {
                // RightRotation
                _rightRotation(n);
            }
            else {
                // Left-Right Rotation
                _leftRotation(n->leftChild);
                _rightRotation(n);
            }
        }
    }
    void _setHeight(Node* n) {//para actualizar la altura del arbol luego de la rotacion
        n->height = max(_getHeight(n->leftChild), _getHeight(n->rightChild)) + 1;
    }
    int _getHeight(Node* n) {
        return (n) ? n->height : -1;//si el nodo no es nulo, se debe devolver la altura del nodo, sino devuelve -1
    }
public:
    AVLTree(function<void(T)> show, function<bool(T, T)> compare) : _show(show), _compare(compare) {
        _root = nullptr;
        _size = 0ll;
    }
    void insert(T value) {
        _insert(_root, value);
    }
    void preOrder() {
        _preOrder(_root);
    }
    // Rightmost element
    T maximo() {
        Node* aux = _root;
        while (aux->rightChild != nullptr) aux = aux->rightChild;
        return aux->value;
    }
    // Leftmost element
    T mininimo() {
        Node* aux = _root;
        while (aux->leftChild != nullptr) aux = aux->leftChild;
        return aux->value;
    }
    void IterativePreOrder() {
        stack<Node*> s;
        s.push(this->_root);
        while (s.empty() == false) {
            // Saco un nodo de la pila
            Node* n = s.top();
            s.pop();
            // Lo muestro en consola
            _show(n->value);
            // Inserto en la pila a sus hijos derecho e izquierdo,
            // en ese orden, en la pila (si es que no son nulos, claro)
            if (n->rightChild)
                s.push(n->rightChild);
            if (n->leftChild)
                s.push(n->leftChild);
        }
    }
};