inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һֻ�󽭴�����Ѱ���Ĵ�������࣬��ʱ���Ѿ���
��������ʱ���ԴӼװ�������ȥ��
LONG);
        set("no_fight", 1);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if (me->is_busy())
                return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

        message("vision", me->name() + "����һԾ���Ӵ󴬵ļװ�������"
                          "��ȥ��\n", environment(me), ({me}));

        me->move(__DIR__"shatan");
        message("vision", me->name() + "�����˴�����Զ���ĺ������˹�"
                          "����\n", environment(me), ({me}));
        return 1;
}       
