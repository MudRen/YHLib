inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ
�Ƴɣ����������������ͼ�����������ɣ�����ʤ�ա��ذ岻
֪����ʲô�������ģ��������������Ϣ����ֻ�е���������
�ģ��ǳ����������ͨ�������
LONG);
        set("exits",([
                "west" : __DIR__"changl15",
                "east" : __DIR__"changl4",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}