// clever.c �츳��ӱ
// Created by Vin 26/8/2001

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIM "�츳��ӱ" NOR; }

int perform(object me, string skill)
{
        return notify_fail("������ܹ�ʹ����������֪ʶ������Ҫ���á�\n");
}

