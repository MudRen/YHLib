inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
������һ����̫��Ժ�ӣ��Ƕ����书�ĵط����μ���Ȼ
�������壬���Ǻͽ���ȴ���Ÿ�ϵ���ϵ����˶μ�����
������������֣�����������������ĳ��ء����Ͼ�������
��Ժ��������ͨ����һ�����䳡��
LONG);
        set("exits", ([
                "north" : __DIR__"liangong2",
                "southeast" : __DIR__"yongdao1",
        ]));
        set("for_family", "���ϻ���");
        setup();
        replace_program(ROOM);
}
