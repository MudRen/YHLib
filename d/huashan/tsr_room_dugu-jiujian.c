// ���Կ������䶼�̳и��ļ�
// by Rcwiz for yhonline

#include <ansi.h>
#define TSROB __DIR__"tsr_dugu-jiujian"

void init()
{
       object me = this_player();
       object ob;
       
       if (! objectp(ob = find_object(TSROB)))
       {
             write(HIR "TSR �������������뱾վ (admin) ��ϵ��\n" NOR);
             return;
       }

       if (wizardp(me))
       {
                
                write(HIG "\n����ID��" + this_object()->query("room_id") + "\n");
                write(HIG "�����������÷�������кţ�" + ob->query(this_object()->query("room_id")) +
                          "\n"NOR);
                write(HIG "��ȷ����˳��F��A��B��C��D��E\n" NOR);
                
       }
       
       add_action("do_move", "move");
}

int do_move(string arg)
{
       object me = this_player();
       object ob;
       string room_id;
       
       if (! arg || arg != "desk")
             return notify_fail("�����ƶ�ʲô��\n");

       if (me->is_busy() || me->is_fighting())
             return notify_fail("����æ������˵�ɣ�\n");

       ob = find_object(TSROB);
       
       if ( ! objectp(ob))
             return notify_fail("TSR ����������������ʦ��ϵ��\n");

       if (ob->query("lock/unlocked"))
             return notify_fail("�����Ѿ������ˣ������Ƕ��һ�١�\n");

       room_id = this_object()->query("room_id");
       room_id = ob->query(room_id);

       if (! stringp(ob->openlock(room_id)))
             return notify_fail("TSR ���ݳ���������ʦ��ϵ��\n");

       me->start_busy(1 + random(2));

       message_vision(HIC "$N" HIC "��ʯ����������ת��ֻ���ò�Զ������"
                      "һ���¡¡�����Ǵ������ص�������\n" NOR, me);

       return 1;
}