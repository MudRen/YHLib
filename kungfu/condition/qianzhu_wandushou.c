#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "qianzhu_wandushou"; }

string chinese_name() { return "��ƶ�"; }

string update_msg_others()
{
       return HIB "ֻ��$N" HIB "������ӿ�������ֳ�һ���������ס�Ĳ�����\n" NOR;
}

string update_msg_self()
{
        return HIB "��ֻ���ƶ����ģ�ͷ��Ŀѣ��һ��˵�����Ķ��ġ�\n" NOR;
}