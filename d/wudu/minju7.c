inherit ROOM;

void create()
{
        set("short", "ѧ��");
        set("long", @LONG
������һ����ª��ѧ�ã��ƺ��������øĳɡ����й���(zhuo)��
������һЩ��λ�����������˻ҳ��������ˡ������ũ��С��������
���������顣 
LONG);

        set("exits", ([
                "west" : __DIR__"cun7",
        ]));
        set("objects", ([
                __DIR__"npc/xuetong": 3,
                __DIR__"npc/xiansheng": 1,
        ]));
         set("item_desc", ([
                "zhuo": "һ���¾ɵĹ�����������źں�����̨��һֱ�������档\n"
        ]) );

        setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg == "" ) return 0;
        if( arg=="zhuo" )
        {
                message("vision", me->name() + "һ�����������������˽�ȥ��\n",
                environment(me), ({me}) );
                me->move(__DIR__"minju9");
                message("vision", me->name() + "���������˽�����\n",
                environment(me), ({me}) );
                return 1;
        }
}       
