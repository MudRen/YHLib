// potential.c Ǭ������
// Created by Vin 4/16/2001

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIB "Ǭ������" NOR; }

int perform(object me, string skill)
{
        return notify_fail("����ܿ�ʹ���ڳ�Ϊ��ʦǰ��Ǳ�ܼӱ�������Ҫ���á�\n");
}

