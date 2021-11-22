//
// Created by 谢铭轩 on 2021/10/14.
//

#ifndef LAB1_GRAMMARANALYSIS_H
#define LAB1_GRAMMARANALYSIS_H

#include "lexicalAnalysis.h"
#include "antiPolandExp.h"
#include "cstdio"
#include "cstdlib"
#include "list"

#define IDENT "Ident"
#define SYMBOL "Symbol"
#define IF_TRUE 1
#define IF_FALSE 2
#define FINAL 3

using namespace std;

typedef struct {
	return_token token;
	bool is_const = false;
	string saved_pointer;
	string saved_register;
} variable_list_elem;

typedef struct {
	int register_num;
	int block_type;
} undefined_code_block_stack_elem;

/**
 * 判断是 token 否在符号表中
 * @return 在符号表中返回 true
 */
bool list_contains(const return_token &);

/**
 * 判断是否为常量
 * @return 是常量返回 true
 */
bool is_variable_const(const return_token &);

void CompUnit(FILE *in, FILE *out);

/**
 * 设置符号表中的变量的储存位置
 */
void set_register(const return_token &, const string &save_register);

/**
 * 获取当前 token 的寄存器位置
 */
string get_register(const return_token &);

/**
 * 获取当前 token 的指针寄存器位置
 */
string get_pointer(const return_token &);

/**
 * 在代码块中刷新符号表
 */
void print_variable_table();

void Decl(FILE *);

void ConstDecl(FILE *);

void BType(FILE *);

void ConstDef(FILE *);

number_stack_elem ConstInitVal(FILE *);

number_stack_elem ConstExp(FILE *);

void VarDecl(FILE *);

void VarDef(FILE *);

number_stack_elem InitVal(FILE *);

void FuncDef(FILE *);

void FuncType(FILE *);

void Block(FILE *);

void BlockItem(FILE *);

void Stmt(FILE *);

number_stack_elem Exp(FILE *);

void Cond(FILE *, bool);

void LVal(FILE *);

void PrimaryExp(FILE *);

void AddExp(FILE *);

void MulExp(FILE *);

void UnaryExp(FILE *);

void FuncRParams(FILE *);

void Ident(FILE *);

void UnaryOp(FILE *);

void RelExp(FILE *);

void EqExp(FILE *);

void LAndExp(FILE *);

void LOrExp(FILE *);

void init();

#endif //LAB1_GRAMMARANALYSIS_H
