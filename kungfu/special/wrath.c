// wrath.c ��ŭ֮��
// Created by Vin 25/5/2002

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIR "��ŭ֮��" NOR; }

int perform(object me, string skill)
{
        return notify_fail("������ܹ�������ļ�ŭ���ޣ�����Ҫ���á�\n");
}

