# Profile

## Création de Profile

```SQL
CREATE PROFILE <nom_profile> LIMIT
    SESSION_PER_USER [{entier | UNLIMITED | DEFAULT}]

    [CPU_PER_SESSION {entier | UNLIMITED | DEFAULT}]

    [CPU_PER_CALL {entier | UNLIMITED | DEFAULT}]

    [CONNECT_TIME {entier | UNLIMITED | DEFAULT}]

    [IDLE_TIME {entier | UNLIMITED | DEFAULT}]

    [LOGICAL_READS_PER_SESSION {entier | UNLIMITED | DEFAULT}]

    [LOGICAL_READS_PER_CALL {entier | UNLIMITED | DEFAULT}]

    [COMPOSITE_LIMIT {entier | UNLIMITED | DEFAULT}]

    [PRIVATE_SGA {entier [K | M] | UNLIMITED | DEFAULT}]

    [FAILED_LOGIN_ATTEMPS {entier  |  UNLIMITED  |  DEFAULT}]

    [PASSWORD_LIFETIME {entier  |  UNLIMITED  |  DEFAULT}]

    [{PASSWORD_REUSE_TIME  |  PASSWORD_REUSE_MAX} {entier  |  UNLIMITED  |  DEFAULT}]

    [PASSWORD_LOCK_TIME {entier  |  UNLIMITED  |  DEFAULT}]

    [PASSWORD_GRACE_TIME {entier  |  UNLIMITED  |  DEFAULT}]

    [PASSWORD_VERIFY_FUNCTION {fonction  |  NULL  |  DEFAULT}]

    [FAILED_LOGIN_ATTEMPTS max_value]

    [PASSWORD_LIFE_TIME max_value]

    [{PASSWORD_REUSE_TIME | PASSWORD_REUSE_MAX} max_value]

    [PASSWORD_LOCK_TIME max_value]

    [PASSWORD_GRACE_TIME max_value]

    [PASSWORD_VERIFY_FUNCTION {function|NULL|DEFAULT}]
```

## Modification de profile

```SQL
ALTER PROFILE nom_profil LIMIT
    [SESSION_PER_USER {entier | UNLIMITED | DEFAULT}]
    [CPU_PER_SESSION {entier | UNLIMITED | DEFAULT}]
    [CPU_PER_CALL {entier | UNLIMITED | DEFAULT}]
    [CONNECT_TIME {entier | UNLIMITED | DEFAULT}]
    [IDLE_TIME {entier | UNLIMITED | DEFAULT}]
    [LOGICAL_READS_PER_SESSION {entier | UNLIMITED | DEFAULT}]
    [LOGICAL_READS_PER_CALL {entier | UNLIMITED | DEFAULT}]
    [COMPOSITE_LIMIT {entier | UNLIMITED | DEFAULT}]
    [PRIVATE_SGA {entier [K | M] | UNLIMITED | DEFAULT}]
```

## Supression

```SQL
DROP PROFILE <profile_name> [CASCADE];
```

- CASCADE: permet de supprimer le profile pour tous les utilisateurs concérnés en le remplaçant par défault.

## Affectation aux utilisateurs

```SQL
ALTER USER <user_name> PROFILE <profile_name>
```

## Side notes

Pour activer le contrôle des ressources, vous disposez de deux solutions:

1. **positionner la variable RESOUIRCE_LIMIT à true dans le fichier
   d’initialisation**

2. **utiliser la commande**
   ```SQL
   ALTER SYSTEM SET RESOURCE_LIMIT = true;
   ```

# Utilisateur

## Création d'utilisateur

```SQL
CREATE USER nom_utilisateur IDENTIFIED {BY mot_de_passe | EXTERNALLY }
    [DEFAULT TABLESPACE nom_tablespace]
    [TEMPORARY TABLESPACE nom_tablespace]
    [QUOTA [nombre / UNLIMITED] ON nom_tablespace]
    [PROFILE nom_profile]
    [PASSWORD EXPIRE]
    [ACCOUNT {LOCK | UNLOCK}];
```

## Modification d'utilisateur

```SQL
ALTER USER nom_utilisateur IDENTIFIED {BY mot_de_passe | EXTERNALLY }
    [DEFAULT TABLESPACE nom_tablespace]
    [TEMPORARY TABLESPACE nom_tablespace]
    [QUOTA [nombre / UNLIMITED] ON nom_tablespace]
    [PROFILE nom_profile]
    [DEFAULT ROLE {rôle [, rôle, ... ] | ALL | ALL EXCEPT rôle [, rôle, ... ]
    | NONE }]
    [PASSWORD EXPIRE]
    [ACCOUNT {LOCK | UNLOCK}];
```

- Un rôle ne peut être affecté par défaut à un utilisateur que s'il lui a été au préalable alloué par un ordre GRANT.

## Supression d'utilisateur

```SQL
DROP USER <user_name> [CASCADE]
```

# Privilèges

## On distingue deux niveaux de privilèges:

- **Privilège système:** correspond à l'autorisation d'effectuer une action particulière sur la base de données ou sur la définition des objets de la base.

- **privilège objet:** correspond à l'autorisation donnée par un créateur d'un objet particulier à un autre, ou à un ensemble d'autres utilisateurs.

## Pour accomplir des taches d’administration sur une BD

- **Se connecter as Sysoper** Sysoper est le droit (privilège) qui permet à un utilisateur oracle de démarrer / arrêter une base sans être DBA.
- **Se connecter as Sysdba** Sysdba est le droit (privilège) qui permet à un utilisateur oracle de démarrer / arrêter une base en tant que rôle DBA.

**To grant privilèges**

```SQL
Grant sysoper to <username>;
Grant sysdba to <username>;
Exit;
```

## Les privilèges objet:

Pour donner le droit d’accès à une table, vue, séquence, procédure,
fonction ou un package.
Les actions autorisés sur des objets de la base de données

## Les privilèges systèmes:

Pour donner le droit d’exécuter des actions sur un certains type d’objets. Ils autorisent l’exécution d’opérations systèmes.

## Privilèges niveau système

- Le mot-clé **ANY** associé au privilège signifie que le privilège est accordé pour tous les schémas.
- La commande **GRANT** permet d'attribuer un privilège à un utilisateur ou à un groupe d'utilisateurs.
- La commande **REVOKE** permet de supprimer les privilèges.

## Accord des privilèges

- For system privileges
  ```SQL
  GRANT {privilège niveau système | rôle} [,{privilège niveau système | rôle}] .. TO {nom utilisateur | rôle |PUBLIC} [,{nom utilisateur | rôle |PUBLIC}] ... [WITH ADMIN OPTION];
  ```
- For object privileges
  ```SQL
  GRANT privilège objet [,privilège objet] .... ON [schéma.]objet TO {nom_utilisateur | rôle | PUBLIC} [,{nom_utilisateur | rôle | PUBLIC}] ... [WITH GRANT OPTION];
  ```

# Roles

## Création de role

```SQL
CREATE ROLE <nom_rôle> [NOT IDENTIFIED] [IDENTIFIED {BY mot_de_passe | EXTERNALLY}];
```

- Mot_de_passe indique que le mot de passe est obligatoire pour activer le rôle, il est demandé chaque fois que le créateur décide de l’activer par la commande Set Role (pour le protéger).

- Un rôle est créé initialement sans caractéristique. Il faut utiliser l’ordre SQL GRANT pour lui affecter des privilèges ou des rôles.

## Role Prédifinis

- **CONNECT** Ces deux rôles sont définis
- **RESOURCE** pour compatibilité descendante.
- **DBA** Tous les privilèges System avec ADMIN OPTION
- **EXP_FULL_DATABASE** Privilèges pour utiliser export
- **IMP_FULL_DATABASE** Privilèges pour utiliser import
- **DELETE_CATALOG_ROLE** Privilèges DELETE sur DD tables
- **EXECUTE_CATALOG_ROLE** Privilège EXECUTE sur DD packages
- **SELECT_CATALOG_ROLE** Privilège SELECT sur DD tables

## Modification role

```SQL
ALTER ROLE <role_name> [NOT IDENTIFIED] [IDENTIFIED BY mot_de_passe | EXTERNALLY] ;
```

## Affectation/suppression(revoke) role

- Affectation:

  ```SQL
  ALTER USER username
  DEFAULT ROLE { rolename [, rolename]... | ALL [ EXCEPT rolename [, rolename]... ] };
  ```

- Suppression:

  ```SQL
  DROP ROLE nom_rôle
  ```

- Retirer un role:

  ```SQL
  REVOKE <role_name> FROM <user_name>
  ```

- Activation:
  ```SQL
  SET ROLE { nom_rôle [IDENTIFIED BY mot_de_passe] ,nom_rôle  [IDENTIFIED BY mot_de_passe] ....} | ALL [EXCEPT rôle [,rôle] ...] | NONE;
  ```
