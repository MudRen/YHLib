// changan: prison.c
// by Doing

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR "����" NOR);
        set("long", @LONG
����ں����ģ����ϵ�é��Ҳ��ʪ�����ģ�����е������������
���ڼ����������ڵ����ӣ���������������ѹ���
    �Ա���һ������(paizi)��
LONG );
        set("no_fight", 1);
        set("item_desc", ([
                "paizi" : "Խ�������һ�ȡ�\n"
        ]));
}

void catch_back(object me)
{
        message_vision(HIM "��Ȼ����������˹���������Χס$N"
                       HIM "����һ��ʹŹ���ߴ����������ü�"
                       "���������...��\n\n" NOR, me);

        message("vision", HIY "��Ⱥ�����" + me->name() +
                HIY "��û�����ȥ��Ȼ�����ϼ���Ѻ���ˡ�\n\n" NOR,
                environment(me), ({ me }));
}

void catch_ob(object me)
{
        message_vision(HIM "��Ȼ�����ظ��˹�����һ��ץס$N����������ס�����"
                       "�ݵĽе�����վס���㷸���ˣ�������߰ɣ���\n\n" NOR,
                       me);

        message("vision", HIY "��������ȭ���Ű�" + me->name() +
                "���������ˡ�\n\n" NOR,
                environment(me), ({ me }));
}

int free_ob(object me)
{
        string startroom;
        message_vision("����������������˳���������$N���������ˣ������"
                       "���ˣ�Ҫ���ٸҷ������ߺ�...\n\n", me);
        message("vision", "���������" + me->name() +
                "���˳�ȥ... �㲻��̾��һ������\n",
                environment(me), ({ me }));

        tell_object(me, HIR "�㱻��������������˳�����...\n\n" NOR);

        if (me->is_ghost())
                startroom = "/d/death/gate";
        else
                startroom = "/d/changan/baihu1";

        me->set("startroom", startroom);
        me->move(startroom);
        message("vision", "�����������һ���㲵�" + me->name() +
                          "���˳������򿪼���������һ���ͻ�ȥ�ˡ�\n",
                          environment(me), ({ me }));
	return 1;
}

