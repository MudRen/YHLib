// energy.c ���ǻ���
// Created by Vin 26/8/2001

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIC "���ǻ���" NOR; }

int perform(object me, string skill)
{
        return notify_fail("������ܹ�������������������Ҫ���á�\n");
}

