inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������Աߵ�һ��С���������������鷿�ģ�ֻ�Ǻ�Ա
���ʵ���Ҳ�����������װ�����棬���Ծ����γ����д����
�ĵط������аڷ���һ�Ű������ͼ������ӣ����ϸ���õĲ�
����ð��������
LONG);
        set("exits", ([
                "west" : __DIR__"fu-datang",
                "north" : __DIR__"fu-huating",
        ]));
        setup();
        replace_program(ROOM);
}
