inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����һ����̫�ߵ�Сɽ��ɽ����ȥ�����������Ʈ�ż���
�����İ��ơ�һȺ���㷢�����¸¡��Ľ�������ͷ�Ϸɹ�����
��ɽ�³��ǵĲ�ԫ�ϱ���ϡ�ɱ档���ǵľ�ͷ��һ����ΰ�Ĺ�
����·����һ������֮�Ͽ����״ʡ�
LONG);
        set("exits", ([
            "westdown" : __DIR__ "jiayuguan",
            "east" : "/d/lanzhou/ximen",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiu");

        setup();
        replace_program(ROOM);
}

