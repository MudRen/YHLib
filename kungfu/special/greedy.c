// greedy.c ����ת��
// Created by Vin 25/5/2002

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIR "����ת��" NOR; }

int perform(object me, string skill)
{
        return notify_fail("������ܹ��������ʳ�Ｐ��ˮ���ޣ�����Ҫ���á�\n");
}

