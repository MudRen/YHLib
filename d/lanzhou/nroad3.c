inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�����˿��֮·���ӹŴ���������й��������������о�
�ú��Ļ�������һ����Ҫ��½��ͨ���������ڻ���·�ϣ�·��
������������ͩ���������˺��٣�ż���м����������յ�����
�������ϴҴ���ȥ��
LONG);
        set("outdoors", "lanzhou");
        set("exits", ([
                "southeast" : __DIR__"nroad2",
                "northwest" : __DIR__"nroad4",
        ]));

        setup();
        replace_program(ROOM);
}
