inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������һ����ʯ����ϣ���������������ͨ��������
�����ݡ�������һ����ǳأ�����ǽ������Ʈ�������ǳ�
���ˡ�������ȥһƬ�����ͻ�Ұ��
LONG );
        set("exits", ([
            "east"  : "/d/changan/xi-chengmen",
            "west"  : __DIR__"xxroad2",
        ]));
        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}

