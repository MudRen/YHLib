// beep.c

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object obj;
        string no_tell, can_tell;

        if (((int)me->query("jing") < 50) && (! wizardp(me)))
                return notify_fail("�����ھ��񲻼ѣ�Ъ��ɡ�\n");

        if (me->is_busy()) 
                return notify_fail("��������æ���ء�\n");
 
        if (! arg || arg == "")
                return notify_fail("���Ǵ������˭��\n");

        if (arg == me->query("id"))
                return notify_fail("���������Լ���\n");

        obj = find_player(arg);

        if (! obj || ! me->visible(obj)) 
                return notify_fail("û������ˡ�\n");

        no_tell = obj->query("env/no_tell");

        if (wizardp(obj)
           && obj->query("env/invisible")
           && wiz_level(obj) >= wiz_level(me))
                return notify_fail("û������ˡ�\n");

        if (! wizardp(me) && (no_tell == "all" || no_tell == "ALL" ||
            is_sub(me->query("id"), no_tell)))
        {
                can_tell = obj->query("env/can_tell");
                if (! is_sub(me->query("id"), can_tell))
                        return notify_fail("����˲���������������\n");
        }

        message_vision(HIC "$N" HIC "Ū��һ��̶������졫��������\n" NOR, me);
        tell_object(obj, HIW "ֻ�������������������ͣ��ԭ����" + me->name(1) +
                         HIW "�������㡣\n" BEEP BEEP NOR);

        call_out("do_beep", 1, obj);
        call_out("do_beep", 2, obj);
        call_out("do_beep", 3, obj);
        call_out("do_beep", 4, obj);

        if (! wizardp(me))
        {
                me->start_busy(2); 
                me->receive_damage("jing", 50);
        }
        return 1;
}

int do_beep(object obj)
{
        if (! obj) return 1;
        tell_object(obj, BEEP);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��beep <ĳ��>

ֻҪ�����δ����䣬������е��˵������ڱ������ʾ��������

HELP);
        return 1;
}


