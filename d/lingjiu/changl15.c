inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ
�Ƴɣ����������������ͼ�����������ɣ�����ʤ�ա��ذ岻
֪����ʲô�������ģ��������������Ϣ����ֻ�е���������
�ģ��ǳ������һ������ӱ��ߴ�����
LONG);
        set("exits",([
                "west" : __DIR__"changl7",
                "east" : __DIR__"changl8",
                "south" : __DIR__"dating",
                "north" : __DIR__"huayuan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}