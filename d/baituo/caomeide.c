inherit ROOM;

void create()
{
        set("short", "��ݮ��");
        set("long", @LONG
�����ǰ���ɽׯ�����һ���ݮ�أ��ʺ�Ĳ�ݮɢ������
���У����˸е��ǳ�������⡣
LONG);
        set("exits", ([
                "northeast" : __DIR__"shulin1",
        ]));

        set("objects" , ([
                __DIR__"obj/caomei" : random(7),
        ]));

        set("outdoors", "baituo");
        setup();
        replace_program(ROOM);
}
