#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "tougu_zhen"; }

string chinese_name() { return "͸�Ǻ���֮��"; }

string update_msg_others()
{
       return HIC "$Nֻ��һ���溮ɢ���߽�������̸���������֮����ȫ��ͣ�Ĳ�����\n" NOR;
}

string update_msg_self()
{
        return HIC "��е�һ���й��溮���˿ڴ����𣬿���������͸�����ھ��ĸ��ţ�\n" NOR;
}

