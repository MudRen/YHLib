// cunning.c ��������
// Created by Vin 26/3/2002

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIC "��������" NOR; }

int perform(object me, string skill)
{
        return notify_fail("������ܹ�ʹ���ø�������ɹ���ֵ������Ҫ���á�\n");
}

