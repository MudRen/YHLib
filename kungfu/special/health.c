// health.c ����Ǭ��
// Created by Vin 26/8/2001

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return WHT "����Ǭ��" NOR; }

int perform(object me, string skill)
{
        return notify_fail("������ܹ�������������Ѫ������Ҫ���á�\n");
}

