// constitution.c ��������
// Created by Vin 1/9/2001

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIY "��������" NOR; }

int perform(object me, string skill)
{
        return notify_fail("������ܹ�ʹ����Ǹ��ߣ�����Ҫ���á�\n");
}

