#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit "/inherit/condition/damo";

string name() { return "damo_zheyuan"; }

string chinese_name() { return "��Ԫ֮��"; }

string update_msg_others()
{
        return HIM "$N" HIM "��ɫ��Ȼ��䣬�ƶ����ĺ���˳"
               "�������乶��¡�\n" NOR;
}

string update_msg_self()
{
        return HIR "���ﴦһ����𣬺��ֱ�ñ�����������ܵ�"
               "��Ħ��Ԫ���ĸ��š�\n" NOR;
}

string die_reason()
{
        return "��Ԫ����������";
}

int neili_damage(object me, mapping cnd)
{
        int d;

        d = cnd["level"];

        if (d > 300 )
                d = 100 + (d - 300) / 12;
        else
        if (d > 60)
                d = 60 + (d - 60 ) / 6;
        d *= 3;
        if (d < 10) d = 10;

        return d / 2 + random(d);
}
