inherit ROOM;

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
������ʯ����ߵ�һ���壬������һСͤ���治֪������
�ν�������ģ����ۿ�ȥ��ֻ������ʯ��������һʱ���۾���
�����ˡ�
LONG);
        set("outdoors", "kunming");
        set("exits", ([                
                "down" : __DIR__"lianhua",
        ]));
        setup();
        replace_program(ROOM);
}
