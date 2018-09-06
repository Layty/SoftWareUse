/**
 * @file				fish.cpp
 * @brief			���ļ�������������Fish�Ĺ��̡�
 * @author			Mikeqin
 * @date			2013��1��12��������
 * @version			����
 * @par				��Ȩ���� (C), 2013-2023, �������
 * @par History:
 * 1.��    ��: 		2013��1��12��������
 *   ��    ��: 		Mikeqin
 *   �޸�����:	�����ļ�
 *
 * 2.��    ��: 		2013��1��12��������
 *   ��    ��: 		Mikeqin
 *   �޸�����:	���Ӹ�ģ���ע��
*/
#include "fish.h"
#include "ApplyHint.h"
#include "ApplyHouseHint.h"
#include "input.h"
#define SHOW	1	

/**
 * @brief eAttrע��   
*/
enum eAttr {
	NATION, 	
	COLOR, 	
	PET,		
	BEVERAGE,	
	CIGARETTE,	
	HOUSE,	
};

/**
 * @brief	TESTSTRU��ע��
*/
typedef struct TESTSTRU
{
	int var1;
	int var2;
}

#ifdef SHOW
static int g_hint_cnt = 0;///<�˴���ע��Ϊ��д���Ժ��������ӡ�
static bool g_only_size = true;
int g_test_var = 0;
#endif

/**
 *@brief: 		apply_hint
 *@details:		apply_hintע��
 *@param[in]	const CSolutionSet &in_set  
 				CSolutionSet &out_set       
 				CApplyHint *apply_hint      
 				const CHint *hints          
 				int num                     
 *@param[out]	��
 *@retval:		static
 */
static void apply_hint(const CSolutionSet &in_set, CSolutionSet &out_set, CApplyHint *apply_hint,
					   const CHint *hints, int num)
{
	CSolutionSet set;

	set = in_set;
	for (int i=0; i<num; i++) {
		apply_hint->SetHint(hints[i]);
		out_set.RemoveAll();
		apply_hint->Apply(set, out_set);
#ifdef SHOW
		printf("\n\n增加约束: %s\n",HINTS_STR[g_hint_cnt++]);
		if (out_set.GetSize()<=4) {
			out_set.Show();
		}
		else {
			out_set.Show(g_only_size);
			if (g_only_size) {
				printf("...\n");
			}
		}
#endif
		set = out_set;
	}
}

static void apply_self_hint(const CSolutionSet &in_set, CSolutionSet &out_set)
{
	CApplyHint hint;
	apply_hint(in_set, out_set, &hint, SELF_HINT, SELF_HINT_CNT);
}

static void apply_ordered_neighbor_hint(const CSolutionSet &in_set, CSolutionSet &out_set)
{
	CApplyOrderedNeighborHint hint;
	apply_hint(in_set, out_set, &hint, ORDER_NEIGHBOR_HINT, ORDER_NEIGHBOR_HINT_CNT);
}

static void apply_neighbor_hint(const CSolutionSet &in_set, CSolutionSet &out_set)
{
	CApplyNeighborHint hint;
	apply_hint(in_set, out_set, &hint, NEIGHBOR_HINT, NEIGHBOR_HINT_CNT);
}

/**
 *@brief: 		find_solution
 *@details:		�ú����ǹ��ܵ���ڡ�
 *@param[in]	CString &buf  
 *@param[out]	��
 *@retval:		
 */
int find_solution(CString &buf)
{
	CSolutionSet set, new_set;
	CSolution sln;
	int i;

	for (i=0; i<MAGIC_NUM; i++) {
		sln.Init(INIT_HINT[i]);
	}
	set.Add(sln);
#ifdef SHOW
	printf("初始状态\n");
	set.Show();
#endif

	apply_self_hint(set, new_set);

	set = new_set;
	apply_ordered_neighbor_hint(set, new_set);

	set = new_set;
	apply_neighbor_hint(set, new_set);

#ifdef SHOW
	printf("\n推理结束。\n");
#else
	new_set.Show(buf);
#endif
	return new_set.GetSize();
}



